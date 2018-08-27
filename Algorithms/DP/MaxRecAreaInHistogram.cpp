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


class MaxAreaHistogram{
public:
    /*
     * Given an array. Each element of array is height of a histogram.
     * We need to find maximum rectangular area in those histogram.
     * There is many algorithm to do his but this is the best.
     * Time Complexity: O(N).
     * Space Complexity: O(N).
     * Ref.: Tushar
    */

    int max_rec_area(int array[], int n);
    void input_fun();
};

int MaxAreaHistogram::max_rec_area(int array[], int n)
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

void MaxAreaHistogram::input_fun()
{
    int array[] = {4, 1, 4, 4, 1, 4};
    int n = sizeof(array) / sizeof(array[0]);

    int ans = max_rec_area(array, n);

    cout << "Maximum Area of Rectangle is: " << ans << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    MaxAreaHistogram bc;
    bc.input_fun();
return 0;
}

