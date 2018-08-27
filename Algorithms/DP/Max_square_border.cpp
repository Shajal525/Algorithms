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

struct stru{
    int row,col;
    stru(){}
    stru(int r, int c):row(r), col(c){}
};


class SQUAREWALL{
public:
    /*
     * Here we are given a matrix. We need to find maximum subsquare matrix with boundary X.
     * That means anything can be inside a square but sides must be sealed with X.
     * Time Complexity: In worse case O(ROW * COL * max(ROW,COL)). For average case O(ROW * COL).
     * Space complexity: O(ROW * COL).
    */
    int max_square_border(int mat[][COL], int row, int col);
    void input_fun();
};

int SQUAREWALL::max_square_border(int mat[][COL], int row, int col)
{
    // In this dp array we will store number of cosequtive X in each position for both column and row
    stru dp[row+2][col+2];
    int max_square = 0;     // This is for our answer. Initially ans is zero

    for(int i=0; i<=row; i++){
        for(int j=0; j<=col; j++){
            if(i == 0 || j == 0){   // Zero'th row and column is initiliz as zero.
                dp[i][j] = stru(0, 0);
                continue;
            }

            if(mat[i-1][j-1] == 'X'){   // If X found
                max_square = 1;         // There is at least a square of size 1 * 1

                int r = dp[i][j-1].row + 1; // In previous row we check for number of cunsequtive X in row and add one
                int c = dp[i-1][j].col + 1; // In previous col we check for number of consequtive X in col and add one

                dp[i][j] = stru(r, c);  // This is out DP value
            }
            else
                dp[i][j] = stru(0, 0);  // If not X then simply put zero
        }
    }
    // DP array is complete

    // Now we need to find maximum squre
    // We start from bottom
    for(int i=row; i>0; i--){
        for(int j=col; j>0; j--){

            // First we find minimum in this position between row and column
            int mn = min(dp[i][j].row, dp[i][j].col);

            // Now from minimum value minus one till 1. If Max_Square is less then this value
            for(int sq=mn-1; sq>0 && (sq+1) > max_square; sq--){

                // We check if in (j-sq)'th column if number of consequtive X in that column is greater then sq
                // We also check if in (i-j)'th row if number of consequtive X in that row is greater then sq
                // If both the conditions are true then we can say that square of size (sq+1 * sq+1) is possible
                if(dp[i][j-sq].col > sq && dp[i-sq][j].row > sq){
                    max_square = sq+1;
                    break;
                }
            }
        }
    }

    return max_square;
}

void SQUAREWALL::input_fun()
{
    int mat[][COL] = {{ 0,   0,  0,   0,  'X'},
                      {'X',  0, 'X', 'X', 'X'},
                      {'X',  0, 'X',  0,  'X'},
                      {'X', 'X','X', 'X', 'X'},
                      { 0,   0, 'X', 'X', 'X'}
                     };

    int row = sizeof(mat) / sizeof(mat[0]);
    int col = sizeof(mat[0]) / sizeof(mat[0][0]);

    int ans = max_square_border(mat, row, col);

    cout << "The maximum size of square border is: " << ans << " * " << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    SQUAREWALL bc;
    bc.input_fun();
return 0;
}

