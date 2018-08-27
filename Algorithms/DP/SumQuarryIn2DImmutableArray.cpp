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
#define COL 4

class SumQuarryInRectangle{
    int DP[COL][COL];
public:
    /*
     * In this problem we are given a immutable metrix. For each quarry will be given upper left point
     * and lower right point in that matrix. We need to calculate sum in that subrectangle.
     * Time Conplexity for Preprocess: O(N^2).
     * Time Complexiy for quary: O(1).
     * Space Complexity: O(N^2).
     * Ref. : Tushar
    */
    int quary(int upperLeftRow, int upperLeftCol, int lowerRightRow, int lowerRightCol);
    void preprocessDP(int mat[][COL], int row, int col);
    void input_fun();
};

// This part is also easy if we try it on paper.
int SumQuarryInRectangle::quary(int upperLeftRow, int upperLeftCol, int lowerRightRow, int lowerRightCol)
{
    // This value is sum of 0,0 to lowerRightRow,lowerRightcol
    int ans = DP[lowerRightRow][lowerRightCol];

    // If there is some part before upperLeftCol then we must subtract it
    if(upperLeftCol != 0)
        ans = ans - DP[lowerRightRow][upperLeftCol-1];

    // IF there is some part above upperLeftRow then we must subtract it
    if(upperLeftRow != 0)
        ans = ans - DP[upperLeftRow-1][lowerRightCol];

    // If we subtracted both then some part is subtracted twice. So we add that part here
    if(upperLeftCol != 0 && upperLeftRow != 0)
        ans = ans + DP[upperLeftRow-1][upperLeftCol-1];

    return ans;
}

// This algorithm is very easy. If we drow the matrix on paper we can see its very easey
// This DP array will store sum of rectangle from 0,0 to any index
void SumQuarryInRectangle::preprocessDP(int mat[][COL], int row, int col)
{
    DP[0][0] = mat[0][0];

    // If we have a single row then we calculate for all column in this row
    for(int i=1; i<col; i++)
        DP[0][i] = DP[0][i-1] + mat[0][i];

    // If we have single column
    for(int i=1; i<row; i++)
        DP[i][0] = DP[i-1][0] + mat[i][0];

    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){

            // This is the trick. We add upper rectangle andside rectangle. In this addition we added some
            // part twice. So we subtract that part.
            // This is very easy if we try on paper.
            DP[i][j] = mat[i][j] + DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1];

        }
    }

//    for(int i=0; i<row; i++){
//        for(int j =0; j<col; j++)
//            cout << DP[i][j] << " ";
//        cout << endl;
//    }
}

void SumQuarryInRectangle::input_fun()
{
    int mat[][COL] = {{2,  0, -3,  4},
                      {6,  3,  2, -1},
                      {5,  4,  7,  3},
                      {2, -6,  8,  1}};

    int row = sizeof(mat) / sizeof(mat[0]);
    int col = sizeof(mat[0]) / sizeof(mat[0][0]);

    preprocessDP(mat, row, col);

    cout << "Sum of values in this subrectangle is: " << quary(0,1, 2,3) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    SumQuarryInRectangle bc;
    bc.input_fun();
return 0;
}

