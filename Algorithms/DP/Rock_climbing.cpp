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
#define MAX_VAL 300
//int SET(int n,int i) {return (n|(1<<i));}
//int RESET(int n,int i) {return (n&~(1<<i));}
//bool check(int n,int i) {return (n&(1<<i));}
using namespace std;

//Template Ends Here
int dirX[] = {1, 1, 1};
int dirY[] = {-1, 0, 1};

int mat[3][3] = {{-1, 2, 5}, {4, -2, 3}, {1, 2, 10}};
#define ROW 3
#define COL 3

class ROCK{
    int DP[MAX_VAL][MAX_VAL];
public:
    /*
     * In this algorithm we are given an matrix. Our initial position is at (0, 0).
     * We can move toward (i+1, j), (i+1, j-1) and (i+1, j+1)
     * We have to calculate maximum value that we can make from top to bottom.
     * Time complexity: O(Col * Row).
    */
    void input_fun();
    int rock_climbing(int row, int col);
    bool out_of_bound(int row, int col);
};

bool ROCK::out_of_bound(int row, int col)
{
    return (row < 0 || row >= ROW || col < 0 || col >= COL);
}

int ROCK::rock_climbing(int row, int col)
{
    if(out_of_bound(row, col))
        return 0;
    if(row == ROW)
        return DP[row][col] = mat[row][col];
    if(DP[row][col] != INT_MIN)
        return DP[row][col];

    int res = rock_climbing(row+dirX[0], col+dirY[0]);
    res = max(res, rock_climbing(row+dirX[1], col+dirY[1]));
    res = max(res, rock_climbing(row+dirX[2], col+dirY[2]));

    return DP[row][col] = mat[row][col] + res;
}

void ROCK::input_fun()
{
    for(int i=0; i<=ROW; i++)
        for(int j=0; j<=COL; j++)
            DP[i][j] = INT_MIN;
    cout << rock_climbing(0, 0) << endl;
}


int main()
{
    //ios::sync_with_stdio(false);
    cin.tie(NULL);

    ROCK bc;
    bc.input_fun();
return 0;
}

