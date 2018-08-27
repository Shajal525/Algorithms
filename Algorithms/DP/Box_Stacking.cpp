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
int SET(int n,int i) {return (n|(1<<i));}
int RESET(int n,int i) {return (n&~(1<<i));}
bool check(int n,int i) {return (n&(1<<i));}
using namespace std;

//Template Ends Here
struct Node{
    int length,width,height;
    Node(int l, int w, int h):length(l),width(w),height(h){}
    bool operator<(Node n){
        return (this->length*this->width) > (n.length*n.width); // This will help sorting in descending order
    }
};

class BOXSTACK{
    vector<Node> allCombination;
public:
    /*
     * This is Box Stacking algorithm
     * We are given length,width and height of few boxes. We need find max hight we can make using those boxes.
     * Box can go on top of anther box if and only if length and width of top box is less then bottom box.
     * Time Complexity: O((2^N)^2). Here N is number of boxes.
     * Ref: Tushar
     * We can also find resulting combination of boxes if we use path[] array and save which box goes on top of which box
    */
    bool canGoOnTop(Node base, Node top);
    void generateCombination(int mask, int L_W_H[]);
    void BoxStacking(int boxes[][3], int n);
    void input_fun();
};

// Returns true if 'top' can go on top of 'base'
bool BOXSTACK::canGoOnTop(Node base, Node top)
{
    if(base.length > top.length && base.width > top.width)
        return true;
    return false;
}

// This function generates all parmutation of a box's length,width and height
void BOXSTACK::generateCombination(int mask, int L_W_H[])
{
    static int val[3];
    static int ind = 0;
    if(mask == 15){
        allCombination.push_back(Node(val[0],val[1],val[2]));
        return;
    }

    for(int i=1; i<=3; i++){
        if(check(mask, i) == 0){    // If this index is not used till now
            if(ind == 1 && val[ind-1] < L_W_H[i-1]) // We take only those combinations where length is greater then width
                continue;
            val[ind++] = L_W_H[i-1];
            generateCombination(SET(mask, i), L_W_H);
            ind--;
        }
    }
}

void BOXSTACK::BoxStacking(int boxes[][3], int n)
{
    // First step is generating all combinations for all boxes
    for(int i=0; i<n; i++)
        generateCombination(1, boxes[i]);

    // Sort then in reverse order of there (length*width)
    sort(allCombination.begin(), allCombination.end());

    int size = allCombination.size();

    int maxHeightTillThis[size];
    for(int i=0; i<size; i++)   // Initially if we think about single box then max height is its own height.
        maxHeightTillThis[i] = allCombination[i].height;

    for(int i=1; i<size; i++){
        for(int j=0; j<i; j++){
            if(canGoOnTop(allCombination[j], allCombination[i])){   // If i can go on top of j
                maxHeightTillThis[i] = max(maxHeightTillThis[i], maxHeightTillThis[j]+allCombination[i].height);
            }
        }
    }

    int mx = -1;
    for(int i=0; i<size; i++)   // Find max height
        if(mx < maxHeightTillThis[i])
            mx = maxHeightTillThis[i];

    cout << "Max height is: " << mx << endl;
}

void BOXSTACK::input_fun()
{
    int boxes[][3] = {{1,2,4}, {3,2,5}};

    int n = sizeof(boxes)/sizeof(boxes[0]);

    BoxStacking(boxes, n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    BOXSTACK bc;
    bc.input_fun();
return 0;
}

