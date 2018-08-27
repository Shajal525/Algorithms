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
#define MAX_INTEGER_RANGE 10000;


class COUNTINGSORT{
public:
    /*
     * This is a sorting algorithm
     * Time Complexity: O(N+R).
     * Space Complexity: O(N+R).
     * Here R is range of maximum integer.
     * This algorithm don't work if array contains negative numbers.
     * Only works if max integer input is not big so that we can allocate space of that size.
    */
    void input_fun();
    void printArray(int *array, int n);
    int getMax(int *array, int n);
    void countingSort(int *array, int n);
};

void COUNTINGSORT::printArray(int *array, int n)
{
    for(int i=0; i<n; i++)
        cout << array[i] << " ";
    cout << endl;
}

int COUNTINGSORT::getMax(int *array, int n)
{
    int mx = -1;
    for(int i=0; i<n; i++)
        if(mx < array[i])
            mx = array[i];
    return mx;
}

void COUNTINGSORT::countingSort(int *array, int n)
{
    int max_int = getMax(array, n);

    int count[max_int+1];   // Count each element
    for(int i=0; i<=max_int; i++)    // Initialize count array
        count[i] = 0;

    for(int i=0; i<n; i++)  // Count each element
        count[array[i]]++;
    for(int i=1; i<=max_int; i++)   // Cumulatve sum of count array
        count[i] += count[i-1];

    int tmp[n]; // output array
    for(int i=0; i<n; i++){
        int cou = --count[array[i]];
        tmp[cou] = array[i];    // Place the value at position cou and decrease count value
    }
    for(int i=0; i<n; i++)
        array[i] = tmp[i];  // Copy into original array
}

void COUNTINGSORT::input_fun()
{
    int array[] = {523,568,225,42,9,344,5,6,355,155};
    int n = sizeof(array) / sizeof(array[0]);

    countingSort(array, n);

    printArray(array, n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    COUNTINGSORT bc;
    bc.input_fun();
return 0;
}

