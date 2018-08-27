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
#define N 4


class BurstBalloon{
public:
    /*
     * In this problem we are given an array of balloons. We need to find the order in which the to burst so that
     * we can maximize value. If we burst i'th balloon we take the value as balloon[i-1]*balloon[i]*balloon[i+1].
     * If we burst a balloon that value is removed from array. So next time when we take balloon[i-1]*balloon[i]*balloon[i+1]
     * if i-1 balloon is gone we take i-2'th balloon
     * Time Complexity: O(N^3).
     * Space Complexity: O(N^2).
     * Ref. : Tushar
    */

    void printDP(int DP[][N], int n);
    int leftVal(int balloon[], int i);
    int rightVal(int balloon[], int i, int n);
    int max_value(int balloon[], int n);
    void input_fun();
};

void BurstBalloon::printDP(int DP[][N], int n)
{
    // Print DP array for DEBUG
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }
}

int BurstBalloon::leftVal(int balloon[], int i)
{
    if(i < 0)
        return 1;
    return balloon[i];
}

int BurstBalloon::rightVal(int balloon[], int i, int n)
{
    if(i >= n)
        return 1;
    return balloon[i];
}

int BurstBalloon::max_value(int balloon[], int n)
{
    int dp[N][N];

    for(int len=1; len<=n; len++){  // We calculate for length 1 to length n

        for(int i=0; i<=n-len; i++){
            int mx = INT_MIN;
            for(int j=i; j<i+len; j++){ // This means if we burst j'th balloon at last

                int left = 0, right = 0;

                // If there is something at the left then we must burst them first because j'th balloon is
                // last baloon in this length i to i+len-1.
                // If notihg on left we take zero
                if(j != i)
                    left = dp[i][j-1];

                // If there is something on right then we must burst them first because j'th balloon is last
                // If nothing on right we take zero
                if(j != i+len-1)
                    right = dp[j+1][i+len-1];

                // As our rule we take value of left balloon and right balloon and multily them with this balloon.
                // Because j'th balloon is last balloon in this length 'len', we take left right baloon after this length
                int val = leftVal(balloon, i-1) * balloon[j] * rightVal(balloon, i+len, n);

                mx = max(mx, left+right+val);   // take maximum value
            }
            dp[i][i+len-1] = mx;
        }
    }

    //printDP(dp, n);

    return dp[0][n-1];
}

void BurstBalloon::input_fun()
{
    int balloon[] = {3, 1, 5, 8};
    int n = sizeof(balloon)/sizeof(balloon[0]);

    int ans = max_value(balloon, n);

    cout << "Maximum value we can make is: " << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    BurstBalloon bc;
    bc.input_fun();
return 0;
}

