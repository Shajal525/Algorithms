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


class QUICKSORT{
public:
    /*
     * One of the best algorithm for sorting.
     * Time Complexity: Worst Case: O(N * N) but Average Case: O(N Log N).
     * Space Complexity: O(1).
     * Here worst case is very rare.
     * This algorithm is prefered over merge sort for array because merge sort take O(N) extra space.
    */
    void input_fun();
    void printArray(int array[], int n);
    int partition(int array[], int l, int h);
    void quickSortUtil(int array[], int l, int h);
    void quickSortIterativeUtil(int array[], int l, int h);
    void quickSort(int array[], int n);
};

void QUICKSORT::printArray(int array[], int n)
{
    for(int i=0; i<n; i++)
        cout << array[i] << " ";
    cout << endl;
}

int QUICKSORT::partition(int array[], int l, int h) // Main trick is here.
{
    int pivot = l + (h-l)/2;    // Tkae mid point as pivot
    int pre = l;        // Previous position
    if(pivot == pre)
        pre++;
    for(int i=l; i<=h; i++){
        if(array[i] < array[pivot]){    // If less then pivot
            swap(array[i], array[pre++]);   // Swap with previous and increase previous
            if(pre == pivot)    // If pivot and previous and pivot same increase previous
                pre++;
        }
    }
    if(pre > pivot) // If previous cross pivot decrease previous
        pre--;
    swap(array[pivot], array[pre]); // Seap pivot with previous
    return pre; // Pre is the pivot position.
}

void QUICKSORT::quickSortIterativeUtil(int array[], int l, int h)
{
    int stack[h-l+2];   // Maintain stack array to store l and h
    int top = 0;
    stack[top++] = l;
    stack[top++] = h;

    while(top > 0){     // This section is easy
        int high = stack[--top];
        int low = stack[--top];

        int p = partition(array, low, high);
        if(p > low){
            stack[top++] = low;
            stack[top++] = p-1;
        }
        if(high > p+1){
            stack[top++] = p+1;
            stack[top++] = high;
        }
    }
}

void QUICKSORT::quickSortUtil(int array[], int l, int h)    // Easy part
{
    if(l >= h)
        return;
    int p = partition(array, l, h); // p is current pivot index

    quickSortUtil(array, l, p-1);   // From l to p-1
    quickSortUtil(array, p+1, h);   // From p+1 to h
}

void QUICKSORT::quickSort(int array[], int n)
{
   // quickSortUtil(array, 0, n-1);
    quickSortIterativeUtil(array, 0, n-1);
    return;
}

void QUICKSORT::input_fun()
{
    int array[] = {10, 7, 8, 9, 1, 5, 5, 3,2,3,6,5,9,9,5,4,3,6,22,9,5,1};
    int n = sizeof(array) / sizeof(array[0]);

    printArray(array, n);
    quickSort(array, n);
    printArray(array, n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    QUICKSORT bc;
    bc.input_fun();
return 0;
}

