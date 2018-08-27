//Template Starts Here

/*******************************************\
*                                           *
*    Name: S. M. Shaheduzzaman(Shajal)      *
*                                           *
*    Begum Rokeya Uniersity, Rangpur        *
*                                           *
\*******************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<climits>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#define ll long long
#define ui unsigned int
#define MP make_pair
#define INPUT freopen("C://Users/Shajal/Desktop/input.txt", "r+", stdin)
#define OUTPUT freopen("C://Users/Shajal/Desktop/out.txt", "r+", stdout)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define sc scanf
#define pf printf
#define out cout
#define MS(x,y) memset(x,y,sizeof(x))
#define sf(x) scanf("%d", &x)
#define sff(x,y) scanf("%d %d", &x,&y)
#define sfff(x,y,z) scanf("%d %d %d", &x,&y,&z)
#define PR_CASE(x) printf("Case %d: ", x)
#define NL putchar('\n')
#define loop(i,x,y) for(int i=x;i<=y;i++)
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x<y?x:y
#define MAX_VAL 30000
//int SET(int n,int i) {return (n|(1<<i));}
//int RESET(int n,int i) {return (n&~(1<<i));}
//bool check(int n,int i) {return (n&(1<<i));}
using namespace std;

//Template Ends Here


class SELLSTOCK{
public:
    /*
     * Given number of transection we can make, that is K and price of stock on diffrent days.
     * We need to find maximum profit after K transection.
     * Time Complexity: O(NumberOfDays * K). This is best algorithm for this.
     * Space Complexity: O(NumberOfDays * K).
     * Ref. : Tushar. Little bit on critical side but he explained very well.
    */
    int max_profit(int stockPrice[], int N, int K);
    void input_fun();
};

int SELLSTOCK::max_profit(int stockPrice[],int N, int K)
{
    int dp[K][N];   // K is number of transection and N is Number of days. If N=7 then days are 0 to 6.

    // If transection is zero we can not make any profit
    for(int i=0;i<N; i++)
        dp[0][i] = 0;
    // If there is only a single day we can not make any profit
    for(int i=0; i<=K; i++)
        dp[i][0] = 0;

    for(int i=1; i<=K; i++){    // For 1 transection to K transection

        int maxDiff = dp[i-1][0] - stockPrice[0];   // This is formula. Explained below
        for(int j=1; j<N; j++){

            // For each day we need to calculate profit using the formula
            // dp[i][j] = max(dp[i][j-1], stockPrice[j] - stockPrice[m] + dp[i-1][m]).    Where m=0 to j-1.
            // If we don't transect then take dp[i][j-1]
            // Else we buying at m'th day and selling j'th day and dp[i-1][m] is max we can do till m'th day with onle less transection
            // We can skip m=0 to j-1 loop using a trick.
            // In (stockPrice[j] - stockPrice[m] + dp[i-1][m]) formula stockPrice[j] is constent for m=0 to j-1.
            // We left with (dp[i-1][m] - stockPrice[m]). We can calculate this part without extra loop with maxDiff
            // Then we add maxDiff with stockPrice[j].

            int tmp = stockPrice[j] + maxDiff;
            dp[i][j] = max(dp[i][j-1], tmp);

            maxDiff = max(maxDiff, dp[i-1][j]-stockPrice[j]);   // Update maxDiff
        }
    }

    return dp[K][N-1];  // Careful
}

void SELLSTOCK::input_fun()
{
    int stock[] = {2, 5, 7, 1, 4, 3, 1, 3};
    int n = sizeof(stock)/sizeof(stock[0]);

    int K = 3;

    int ans = max_profit(stock, n, K);

    cout << "Maximum profit we can make is: " << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    SELLSTOCK bc;
    bc.input_fun();
return 0;
}

