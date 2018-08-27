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
#define MAXV 1005

struct MAT{
    int row, col;
    MAT(int a, int b) : row(a), col(b){}
};


class MAT_CHAIN_MUL{
    int DP[MAXV][MAXV];
public:
    /*
     * Matrix Chain Multiplication
     * This algorithm finds minimum cost for multiplying more then two matrix's
     * Time Complexity: O(N^3).
     * Space Complexity: O(N^2).
    */
    void input_fun();
    int chain_mul_iterative_util(MAT mat[], int siz);
    int chain_mul_util(MAT mat[], int l, int r);
    int chain_multioication(MAT mat[], int n);
};

int MAT_CHAIN_MUL::chain_mul_iterative_util(MAT mat[], int siz)
{
    for(int i=0; i<=siz; i++){
        DP[i][i] = 0;           // This is for length 1
    }
    for(int len=1; len<siz; len++){      // len=1 means for length 2 and so on

        for(int st=1; st+len<=siz; st++){     // start index
            int minn = INT_MAX;
            for(int m=st; m<st+len; m++){   // From start to start+len calculate for each mid
                int tmp = DP[st][m] + DP[m+1][st+len] + mat[st-1].row * mat[m-1].col * mat[st+len-1].col; // left + right + costof(lafr*right)
                minn = min(minn, tmp);
            }
            DP[st][st+len] = minn;
        }
    }
    return DP[1][siz];
}

int MAT_CHAIN_MUL::chain_mul_util(MAT mat[], int l, int r)
{
    if(r <= l)
        return 0;
    if(DP[l][r] != -1)
        return DP[l][r];
    int minn = INT_MAX;
    for(int mid=l; mid < r; mid++){
        int left = chain_mul_util(mat, l, mid);     // Find cost for multiplying left
        int right = chain_mul_util(mat, mid+1, r);  // Cst for right side
        int mul = mat[l].row * mat[mid].col * mat[r].col;   // Cost for multiplying left and rihgt.

        int total_cost = left + right + mul;    // Total cost
        minn = min(minn, total_cost);           // Find min
    }
    return DP[l][r] = minn;
}

int MAT_CHAIN_MUL::chain_multioication(MAT mat[], int n)
{
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            DP[i][j] = -1;

    //int ans = chain_mul_util(mat, 0, n-1);
    int ans = chain_mul_iterative_util(mat, n);

    cout << "Minimum chain multiplication is : " << ans << endl;

    return ans;
}

void MAT_CHAIN_MUL::input_fun()
{
    MAT mat[] = {MAT(1, 2), MAT(2, 3), MAT(3, 4)};
    int n = sizeof(mat) / sizeof(mat[0]);

    chain_multioication(mat, n);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    MAT_CHAIN_MUL bc;
    bc.input_fun();
return 0;
}

