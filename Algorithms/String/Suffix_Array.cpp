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
#define MAXL 500    // Max length of text
#define MAXP 50     // Log MAXL

struct items{
    int st_ind;     // Start index of suffix
    int a;
    int b;
    bool operator<(const items it){
        return (it.a == a) ? it.b > b : it.a  > a;
    }
}itm[MAXL];

int arr[MAXL][MAXP];    // Weight of value of string of length 2^i starting from index i.

class SUFFIX_ARRAY{
    int size;
public:
    /*
     * Suffix array can be used to solve many complex problen in lenier time frame.
     * Time complexity of building suffix array is O(N * log N * log N).
     * If we use radix sort then this can be done in O(N * log N) time.
     * Everything we can do with suffix tree can also be done with suffix array.
     *
    */
    void input_fun();
    void build_suffix_array(string text);
    void print_array();
};

void SUFFIX_ARRAY::build_suffix_array(string text)
{
    for(int i=0; i<size; i++)
        arr[i][0] = text[i] - 'a';  // Initialize arr for length 1

    int Log = log2(size);

    for(int j=1; j<=Log; j++){
        for(int i=0; i<size; i++){
            itm[i].st_ind = i;      	// Save index
            itm[i].a = arr[i][j-1]; 	// Use suffix value for a
            if(i + (1 << (j-1)) < size)
                itm[i].b = arr[i+(1 << (j-1))][j-1];
            else itm[i].b = -1;
        }

        sort(itm, itm+size);

        arr[itm[0].st_ind][j] = 0;
        int count = 0;
        for(int i=1; i<size; i++){
            if(itm[i].a == itm[i-1].a && itm[i].b == itm[i-1].b)
                arr[itm[i].st_ind][j] = count;                  // Update sorted value of array.
            else
                arr[itm[i].st_ind][j] = ++count;
        }
    }
}

void SUFFIX_ARRAY::print_array()
{
    for(int i=0; i<size; i++)
        cout << itm[i].st_ind << " ";
    cout << endl;
}

void SUFFIX_ARRAY::input_fun()
{
    string text = "banana";
    //cin >> text;
    size = text.length();

    build_suffix_array(text);
    print_array();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    SUFFIX_ARRAY bc;
    bc.input_fun();
return 0;
}

