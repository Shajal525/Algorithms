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


class HEAPSORT{
    int *heap_array;
    int heap_size;
    int capacity;
public:
    /*
     * Time complexity: O(N * log N).
     * Space Complexity: O(1).
     * Algorithm is simple, easy to implement.
    */
    HEAPSORT(){
        heap_array = NULL;
        heap_size = 0;
        capacity = 500;
    }
    void input_fun();
    int parent(int index);
    int left(int index);
    int right(int index);
    void printHeap();
    int getMax();
    void maxHeapify(int index, int n);
    void heapSort(int array[], int n);
};

int HEAPSORT::parent(int ind)   // Returns Parent of ind
{
    return (ind-1)/2;
}

int HEAPSORT::left(int ind) // Returns Left chield of ind
{
    return ind*2 + 1;
}

int HEAPSORT::right(int ind)    // Returns Right chield of ind
{
    return ind*2 + 2;
}

void HEAPSORT::printHeap()
{
    for(int i=0; i<heap_size; i++)
        cout << heap_array[i] << " ";
    cout << endl;
}

int HEAPSORT::getMax()
{
    if(heap_size == 0)
        return INT_MAX;
    return heap_array[0];
}

void HEAPSORT::maxHeapify(int index, int n) // Normal max Heapify function
{
    int l = left(index);
    int r = right(index);
    int greatest = index;
    if(l < n && heap_array[greatest] < heap_array[l])
        greatest = l;
    if(r < n && heap_array[greatest] < heap_array[r])
        greatest = r;

    if(greatest != index){
        swap(heap_array[greatest], heap_array[index]);
        maxHeapify(greatest, n);
    }
}

void HEAPSORT::heapSort(int array[], int n)
{
    heap_array = array;
    heap_size = n;
    // This is the way to convart a normal array into a heap. To do that we need to do heapify from bottom to top
    // All nodes after (n-2)/2 to n-1 is leaf node. So we do it from (n-2)/2 to 0
    // Looks like this loop will take O(N * log N) time but it is proved that it takes O(N) time.
    for(int i= (n-2)/2; i>=0; i--)
        maxHeapify(i, n);

    for(int i=n-1; i>=0; i--){
        swap(heap_array[0], heap_array[i]); // Swap max element which is at 0 index with last index
        maxHeapify(0, i);   // Heapify from root to i index
    }
}

void HEAPSORT::input_fun()
{
    int array[] = {12, 11, 13, 5, 6, 7, 10, 7, 8, 9, 1, 5, 5, 3,2,3,6,5,9,9,5,4,3,6,22,9,5,1};
    int n = sizeof(array)/sizeof(array[0]);

    heapSort(array, n);
    printHeap();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    HEAPSORT bc;
    bc.input_fun();
return 0;
}

