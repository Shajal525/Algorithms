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

class HEAP{
    int *heap_array;
    int heap_size;
    int capacity;
public:
    /*
     * This is min Heap data structure. MaxHeap is almost same
     * We can access minimum(In minHeap) in O(1) time.
     * Insert and delete take O(log N) time. Search will take O(N) time.
    */
    HEAP(int capacity){
        heap_size = 0;
        this->capacity = capacity;
        heap_array = new int[capacity];
    }
    int parent(int ind);
    int left(int ind);
    int right(int ind);
    void printHeap();
    void heapify(int ind);
    void arrayToHeap(int array[], int n);
    int getMin();
    int extractMin();
    void replace(int ind, int n_val);
    int find(int val);
    void insert(int val);
    void deletee(int index);
};

int HEAP::parent(int ind)   // Returns Parent of ind
{
    return (ind-1)/2;
}

int HEAP::left(int ind) // Returns Left chield of ind
{
    return ind*2 + 1;
}

int HEAP::right(int ind)    // Returns Right chield of ind
{
    return ind*2 + 2;
}

void HEAP::printHeap()
{
    for(int i=0; i<heap_size; i++)
        cout << heap_array[i] << " ";
    cout << endl;
}

void HEAP::arrayToHeap(int array[], int n)
{
    heap_array = array;
    heap_size = n;
    // This is the way to convart a normal array into a heap. To do that we need to do heapify from bottom to top
    // All nodes after (n-2)/2 to n-1 is leaf node. So we do it from (n-2)/2 to 0
    // Looks like this loop will take O(N * log N) time but it is proved that it takes O(N) time.
    for(int i= (n-2)/2; i>=0; i--)
        heapify(i);
}

void HEAP::heapify(int ind)
{
    if(ind >= heap_size)
        return;
    int l = left(ind);
    int r = right(ind);
    int lowest = ind;
    if(l < heap_size && heap_array[lowest] > heap_array[l]) // Check if left chield is lower then ind
        lowest = l;
    if(r < heap_size && heap_array[lowest] > heap_array[r]) // Check for right chield
        lowest = r;

    if(lowest != ind){  // If lowest is left or right chield
        swap(heap_array[lowest], heap_array[ind]);  // swap with ind
        heapify(lowest);    // Do same process for lowest chield
    }
}

int HEAP::getMin()  // Return minimum
{
    if(heap_size == 0)
        return INT_MIN;
    return heap_array[0];
}

int HEAP::extractMin()  // Return minimum and delete minimum
{
    if(heap_size == 0)
        return INT_MIN;
    if(heap_size == 1){
        return heap_array[--heap_size];
    }
    int re = heap_array[0];
    heap_array[0] = heap_array[--heap_size];  // Make last element fist element

    heapify(0); // Heapify from root
    return re;
}

void HEAP::replace(int ind, int n_val)  // Replace value at index ind with n_val
{
    if(ind >= heap_size)
        return;
    heap_array[ind] = n_val;    // Update value
    int p = parent(ind);
    while(ind > 0 && heap_array[p] > heap_array[ind]){  // Check if parent is greater then n_val
        swap(heap_array[p], heap_array[ind]);   // Swap with parent
        ind = p;
        p = parent(ind);
    }
    heapify(ind);   // Need to use heapify. It will work if n_val is greater then previous value
}

void HEAP::deletee(int index)
{
    replace(index, INT_MIN);    // Replace with INT_MIN
    extractMin();               // Then extrack
}

int HEAP::find(int val)
{
    for(int i=0; i<heap_size; i++)  // Find is O(N) operation.
        if(val == heap_array[i])
            return i;
    return INT_MIN;
}

void HEAP::insert(int val)
{
    if(heap_size == capacity){
        cout << "Heap already full" << endl;
        return;
    }
    heap_array[heap_size++] = val;
    int ind = heap_size-1;
    int p = parent(ind);
    while(ind > 0 && heap_array[p] > heap_array[ind]){  // Check if parent is greater then new value
        swap(heap_array[p], heap_array[ind]);    // Swap with parent
        ind = p;
        p = parent(ind);
    }
}

void input_fun()
{
    HEAP *heap = new HEAP(11);
    heap->insert(3);
    heap->insert(2);
    heap->deletee(1);
    heap->insert(15);
    heap->insert(5);
    heap->insert(4);
    heap->insert(45);
    heap->printHeap();

//    int array[] = {2, 15, 5, 4, 45};
//    int n = sizeof(array) / sizeof(array[0]);
//    HEAP *heap = new HEAP(0);
//    heap->arrayToHeap(array, n);
//    heap->printHeap();

    cout << heap->extractMin() << endl;
    heap->printHeap();
    cout << heap->getMin() << endl;
    heap->replace(2, 1);
    cout << heap->getMin() << endl;
    heap->printHeap();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input_fun();
return 0;
}

