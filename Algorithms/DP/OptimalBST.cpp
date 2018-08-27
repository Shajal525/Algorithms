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
#define MAXV 1001

class OPTIMAL{
    int dp[MAXV][MAXV];
public:
    /*
     * Optimal BST
     * Referance: Tushar Roy
     * Time Complexity: O(N^3).
    */

    int optimalBST(int frequency[], int size);
    void input_fun();
};

int OPTIMAL::optimalBST(int frequency[], int size)
{
    for(int i=0; i<size; i++)
        dp[i][i] = frequency[i];

    for(int l=2; l<=size; l++){
        for(int st=0; st<size; st++){
            int mn = INT_MAX;
            int sum_of_fre = 0;
            for(int i=st; i<st+l; i++){ // Take i as root and find both sides tree.
                sum_of_fre += frequency[i];
                int s = 0;
                if(i != st){    // For left tree
                    s = dp[st][i-1];
                }
                if(i != st+l-1){    // For right tree.
                    s += dp[i+1][st+l-1];
                }
                mn = min(mn, s);    // Find min
            }
            dp[st][st+l-1] = sum_of_fre + mn;   // This result
        }
    }
    return dp[0][size-1];
}

void OPTIMAL::input_fun()
{
    int vals[] = {10, 12, 16, 21};
    int frequency[] = {4, 2, 6, 3};
    int size = sizeof(vals)/sizeof(vals[0]);

    int ans = optimalBST(frequency, size);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    OPTIMAL bc;
    bc.input_fun();
return 0;
}

