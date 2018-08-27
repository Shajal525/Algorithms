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
#define ROW 4
#define COL 5

struct Node{
    int max_sum, up, down;
    Node(int m, int u, int d):max_sum(m), up(u), down(d){}
};

class SUB_RECTANGLE{
public:
    /*
     * This algorithm finds Maximum Sub Matrix in a given Rectangle.
     * Time Complexity: (Col * Col * Row).
     * This algorithm only works if there is at least one positive number.
     * This algorithm uses Kanath's Max sum Subarray algorithm.
     * Referance: Tushar
    */
    void add_this_col(int rectangle[][COL], int array[], int row, int col);
    Node max_subarray_in_array(int array[], int row);
    void max_sum_sub_rectangle(int rectangle[][COL], int row, int col);
    void input_fun();
};

void SUB_RECTANGLE::add_this_col(int rectangle[][COL], int array[], int row, int col)
{
    // This function add all row in given 'col' to array
    for(int i=0; i<row; i++)
        array[i] += rectangle[i][col];
}

Node SUB_RECTANGLE::max_subarray_in_array(int array[], int row)
{
    // This is Kanath's Max Subarray sum algorithm
    int max_ending_here = 0;    // Here we initializ as 0
    int max_sum = INT_MIN;
    int start_ind, end_ind, s=0;
    for(int i=0; i<row; i++){
        // Simply add with max_ending_here
        max_ending_here = max_ending_here + array[i];

        if(max_sum < max_ending_here){   // Check for max
            max_sum = max_ending_here;
            start_ind = s;  // Change start and end index
            end_ind = i;
        }
        if(max_ending_here < 0){    // If less then zero make it zero
            max_ending_here = 0;
            s = i+1;    // Change start index
        }
    }

    return Node(max_sum, start_ind, end_ind);
}

void SUB_RECTANGLE::max_sum_sub_rectangle(int rectangle[][COL], int row, int col)
{
    int array[row];
    int max_sum = INT_MIN;
    int max_left = 0, max_right = 0, max_up = 0, max_down = 0;

    for(int l=0; l<col; l++){   // We take l as left

        memset(array, 0, sizeof(array));    // Initializ array to 0

        for(int r=l; r<col; r++){   // R here is right

            add_this_col(rectangle, array, row, r); // Add Column r to array
            Node node = max_subarray_in_array(array, row);  // Use Kadan's Algorithm to find max Sum Subarray in array

            if(max_sum < node.max_sum){ // If current sum is greater then previous max
                max_sum = node.max_sum; // Update max and rectangle sides
                max_up = node.up;
                max_down = node.down;
                max_left = l;
                max_right = r;
            }
        }
    }

    cout << "Max Rectangle Sub matrix sum is: " << max_sum << endl;
    cout << "Left: " << max_left << " Up: " << max_up << " Right: " << max_right << " Down: " << max_down << endl;
}

void SUB_RECTANGLE::input_fun()
{
    int rectangle[][COL] = {{2, 1, -3, -4, 5},
                            {0, 6, 3, 4, 1},
                            {2, -2, -1, 4, -5},
                            {-3, 3, 1, 0, 3}};

    max_sum_sub_rectangle(rectangle, ROW, COL);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    SUB_RECTANGLE bc;
    bc.input_fun();
return 0;
}

