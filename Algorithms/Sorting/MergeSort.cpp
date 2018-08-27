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


class MERGESORT{
public:
    /*
     * Sorting algorithm
     * Time Complexity: O(N * log N).
     * Space Complexity: O(N).
     * This is not prefered for array because it needs extra O(N) space. QuickSort is prefered over this.
    */
    void input_fun();
    void mergeSortUtil(int array[], int l, int r);
    void merge(int array[], int l, int m, int r);
    void mergeSortIterativeUtil(int array[], int n);
    void mergeSort(int array[], int n);
    void printArray(int array[], int n);
};

void MERGESORT::printArray(int array[], int n)
{
    for(int i=0; i<n; i++)
        cout << array[i] << " ";
    cout << endl;
}

void MERGESORT::merge(int array[], int l, int m, int r)
{
    int tmp[r-l+3];
    int left = l, right = m+1, i=0;
    while(left <= m && right <= r){
        if(array[left] < array[right])
            tmp[i++] = array[left++];
        else
            tmp[i++] = array[right++];
    }

    while(left <= m)
        tmp[i++] = array[left++];

    while(right <= r)
        tmp[i++] = array[right++];

    i=0;
    for(int j=l; j<=r; j++){
        array[j] = tmp[i++];
    }
return;
}

void MERGESORT::mergeSortIterativeUtil(int array[], int n)  // Iterative version
{
    for(int cur_len=1; cur_len < n; cur_len *= 2){  // Length of array we working with
        for(int i=0; i<n-cur_len; i += 2*cur_len){
            int mid = i + cur_len - 1;
            int right = min(i + 2*cur_len - 1, n-1);
            merge(array, i, mid, right);
        }
    }
}

void MERGESORT::mergeSortUtil(int array[], int l, int r)
{
    if(l >= r)
        return;
    int mid = l + (r-l) / 2;

    mergeSortUtil(array, l, mid);
    mergeSortUtil(array, mid+1, r);
    merge(array, l, mid, r);
    //printArray(array, r);
return;
}

void MERGESORT::mergeSort(int array[], int n)
{
  //  mergeSortUtil(array, 0, n-1);
    mergeSortIterativeUtil(array, n);
}

void MERGESORT::input_fun()
{
    int array[] = {12, 11, 13, 5, 6, 7, 5, 20, 9, 3};
    int n = sizeof(array) / sizeof(array[0]);

    printArray(array, n);
    mergeSort(array, n);
    printArray(array, n);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    MERGESORT bc;
    bc.input_fun();
return 0;
}

