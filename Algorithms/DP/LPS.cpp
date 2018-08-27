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

class LPS{
    int dp[MAXV][MAXV];
public:
    /*
     * Longest Palindromic Subsequence
     * Time Complexity: O(N*N).
     * Ref: Tushar
     * We can get Longest Palindromic Substring if we make some tweak.
    */
    int lps(string inp_str);
    void input_fun();
};

int LPS::lps(string inp_str)
{
    int len = inp_str.length();
    for(int i=0; i<len; i++)
        dp[i][i] = 1;       // For Length on palindrom is 1

    for(int l=1; l<len; l++){   // Here l=1 means length two. So length = len when l-1=len
        for(int st=0; st+l<len; st++){
            if(inp_str[st] != inp_str[st+l]){   // If mismatch found we take max of left or upper box in dp
                dp[st][st+l] = max(dp[st][st+l-1], dp[st+1][st+l]);
            }
            else{   // If match found we add 2 with middle part
                dp[st][st+l] = 2 + dp[st+1][st+l-1];
            }
        }
    }
    return dp[0][len-1];
}

void LPS::input_fun()
{
    string str = "agbdba";
    int ans = lps(str);

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    LPS bc;
    bc.input_fun();
return 0;
}

