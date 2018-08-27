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


class MAX_SUMARRAY_SUM{
public:
    /*
     * This is Kadane’s Algorithm for finding Maximum Subarray Sum.
     * Time Complexity: O(N).
     * Best Algorithm for subarray sum.
    */
    int max_subarray_sum(int array[], int n);
    int max_subarray_sum_with_range(int array[], int n);
    void input_fun();
};

// This function can also handle all negative values
int MAX_SUMARRAY_SUM::max_subarray_sum(int array[], int n)
{
    int max_ending_here=array[0];   // Initializ as fist node in array
    int max_so_far=array[0];

    for(int i=1; i<n; i++){
        // Take max of this array and this array + max till its previous index
        max_ending_here = max(array[i], max_ending_here + array[i]);

        // Save maximum value in max_so_far
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

// This function also can handle all negative values
int MAX_SUMARRAY_SUM::max_subarray_sum_with_range(int array[], int n)
{
    int max_ending_here = 0;    // Here we initializ as 0
    int max_so_far = INT_MIN;
    int start_ind, end_ind, s=0;
    for(int i=0; i<n; i++){
        // Simply add with max_ending_here
        max_ending_here = max_ending_here + array[i];

        if(max_so_far < max_ending_here){   // Check for max
            max_so_far = max_ending_here;
            start_ind = s;  // Change start and end index
            end_ind = i;
        }
        if(max_ending_here < 0){    // If less then zero make it zero
            max_ending_here = 0;
            s = i+1;    // Change start index
        }
    }

    cout << "Max subarray sum is: " << max_so_far << " Starting index: " << start_ind << " Ending index: " << end_ind << endl;
    return  max_so_far;
}

void MAX_SUMARRAY_SUM::input_fun()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
//    int max_sum = max_subarray_sum(a, n);
//    cout << max_sum << endl;

    max_subarray_sum_with_range(a, n);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    MAX_SUMARRAY_SUM bc;
    bc.input_fun();
return 0;
}

