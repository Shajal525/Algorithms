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
#define PI 3.1415926535897932384626
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x<y?x:y
#define MAX_VAL 30000
//int SET(int n,int i) {return (n|(1<<i));}
//int RESET(int n,int i) {return (n&~(1<<i));}
//bool check(int n,int i) {return (n&(1<<i));}
using namespace std;

//Template Ends Here
int SET(int n, int i) {return  (n|(1<<i));}
int RESET(int n, int i) {return  (n & ~(1<<i));}
bool CHECK(int n, int i) {return (n&(1<<i));}
#define MAXV 1<<17
#define MATV 1<<2
int mat[][2] = {{10, 10}, {90, 10}};

class BITMASK{
    int DP[MAXV];
public:
    /*
     * Bitmask DP.
     * Referance: Safayats Blog.
     * Time Complexity: O(N^2 * 2^N). Preety hugeee.
     * Only works if value of N is low.
     * The consept below is solution of LightOJ_1119
    */

    void input_fun();
    int bitmaskDP(int mask, int n);
};

int BITMASK::bitmaskDP(int mask, int n)
{
    if(mask == (1<<n)-1)
        return 0;
    if(DP[mask] != -1)
        return DP[mask];

    int mn= 1<<28;
    for(int i=0; i<n; i++){         // Like permutation genaration
        if(CHECK(mask, i) == 0){
            int sum = mat[i][i];
            for(int j=0; j<n; j++)
                if(CHECK(mask, j) == 1)
                    sum += mat[i][j];
            sum = sum + bitmaskDP(SET(mask, i), n);

            mn = min(mn, sum);
        }
    }
    return DP[mask]=mn;
}

void BITMASK::input_fun()
{
    int n = 2;
    for(int i=0; i<=MATV; i++)
        DP[i] = -1;
    cout << bitmaskDP(0, n) << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    BITMASK bc;
    bc.input_fun();
return 0;
}

