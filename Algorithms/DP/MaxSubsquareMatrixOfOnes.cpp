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
#define COL 5


class SUBSQUARE{
public:
    /*
     * Given a matrix of zero and one. We need to find maximum size subsquare matrix of one's.
     * We already wrote algorithm for maximum size subrectangle matrix. This is easier.
     * Time Complexity: O(ROW * COL).
     * Space Complexity: O(ROW * COL).
    */
    int max_subsquare_matrix(int mat[][COL], int row, int col);
    void input_fun();
};

int SUBSQUARE::max_subsquare_matrix(int mat[][COL], int row, int col)
{
    int dp[row+2][col+2];

    for(int i=0; i<=row; i++)   // Initializ top row and left column as zero
        dp[i][0] = 0;
    for(int i=0; i<=col; i++)
        dp[0][col] = 0;

    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){

            // If mat is one we take minimum of (dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) Plus one.
            if(mat[i-1][j-1] == 1){
                int tmp = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = min(tmp, dp[i-1][j-1]) + 1;
            }
            // Else we simply put zero.
            else
                dp[i][j] = 0;
        }
    }

    return dp[row][col];    // This is the answer.
}

void SUBSQUARE::input_fun()
{
    int mat[][COL] = {{0, 0, 1, 1, 1},
                      {1, 0, 1, 1, 1},
                      {0, 1, 1, 1, 1},
                      {1, 0, 1, 1, 1}};

    int row = sizeof(mat) / sizeof(mat[0]);

    int ans = max_subsquare_matrix(mat, row, COL);

    cout << "Size of Maximum subsquare matrix is: " << ans << " \* " << ans << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    SUBSQUARE bc;
    bc.input_fun();
return 0;
}

