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
#define COL 6

class MaxRecOf1s{
public:
    /*
     * We are given a matrix of 1 and 0. We need to find maximum area rectangle of 1's.
     * The idea is to take one row at a time and use maximum Rectangle area on Histogram algorithm for this row.
     * Then add next row with this one and put zero if value is zero and again use that algorithm.
     * Time Complexity: O(ROW * COL).
     * Ref.: Tusher
    */
    int maxAreaOnes(int array[][COL], int row, int col);
    int max_rec_areaOnHistogram(int array[], int n);
    void input_fun();
};

int MaxRecOf1s::max_rec_areaOnHistogram(int array[], int n)
{
    stack<int> stk; // We will insert index in this stack
    stk.push(0);
    int max_area = -1;
    // We will push every index if value is bigger then or equalto this value
    for(int i=1; i<n; i++){

        // If value of stack top index is les then or equalto array[i]
        if(array[stk.top()] <= array[i])
            stk.push(i);
        else{
            // We will pop until we reach a value which is less then or equal or stack is empty
            while(!stk.empty() && array[stk.top()] > array[i]){
                int area = 0;
                int top = stk.top();
                stk.pop();

                if(stk.empty()){
                    // If stack is empty that means this is last index in stack and until now this is the smallest
                    // So we multiply this with i
                    area = array[top] * i;
                }
                else{
                    // This is the formula for max area.
                    area = array[top] * (i - stk.top() - 1);
                }

                max_area = max(max_area, area);
            }
            stk.push(i);
        }
    }

    // Check again if stack is not empty.
    while(!stk.empty()){
        int area = 0;
        int top = stk.top();
        stk.pop();

        if(stk.empty()){
            area = array[top] * n;
        }
        else{
            area = array[top] * (n - stk.top() - 1);
        }
        max_area = max(max_area, area);
    }

    return max_area;
}

int MaxRecOf1s::maxAreaOnes(int array[][COL], int row, int col)
{
    int tmp[col+1];
    for(int i=0; i<=col; i++)   // Initializ as zero
        tmp[i] = 0;

    int max_area = 0;
    for(int i=0; i<row; i++){

        for(int j=0; j<col; j++){   // For this row
            if(array[i][j] == 0)    // Put zero if value is zero
                tmp[j] = 0;
            else                    // Else Add the value in tmp array
                tmp[j] += array[i][j];
        }

        int area = max_rec_areaOnHistogram(tmp, col);   // Use this algorithm to calculate max area
        max_area = max(max_area, area);
    }

    return max_area;
}

void MaxRecOf1s::input_fun()
{
    int array[][6] ={{1,0,0,1,1,1},
                     {1,0,1,1,0,1},
                     {0,1,1,1,1,1},
                     {0,0,1,1,1,1}};
    int col = COL;
    int row = sizeof(array)/sizeof(array[0]);

    int ans = maxAreaOnes(array, row, col);

    cout << "Maximum area rectangle of one's is: " << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    MaxRecOf1s bc;
    bc.input_fun();
return 0;
}

