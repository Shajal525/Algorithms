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
struct tree{
    int node;

    struct tree *left, *right;

    tree(){}
    tree(struct tree *l, struct tree *r, int n){
        node = n;
        left = l;
        right = r;
    }
};

int arr[MAX_VAL];
struct tree *version[MAX_VAL];  // Array of tree to create new tree in each update

class PST{
    struct tree *root;
public:
    void initializ(){}
    void input_fun();
    /*
        Everything is same as Segment Tree.

        This version will help us answer sum quarry after any number of update.
        Because we will save separate tree after each update

        Reference : geeksforgeeks
    */
    void build_tree(struct tree *cur_root, int s, int e);
    int quary(struct tree *cur_root, int hi, int low, int l, int r);

    /*
        There is slight difference in Update operation.

        We have to save each Update in different tree
    */
    void update(struct tree *pre, struct tree *curr, int s, int en, int pos, int val);
};

int PST::quary(struct tree *cur_root, int low, int hi, int l, int r)
{
    if(l > hi || r < low || low > hi)
        return 0;

    if(l <= low && r >= hi)
        return cur_root->node;

    int mid = (low + hi) / 2;

    return quary(cur_root->left, low, mid, l, r) + quary(cur_root->right, mid+1, hi, l, r);
}

// We will create and save new tree in *curr
// There will be no effect on *pre. It will remain same
void PST::update(struct tree *pre, struct tree *curr, int s, int en, int pos, int val)
{
    if(pos < s || pos > en)
        return;
    if(s == en){
        curr->node = val;
        return;
    }

    int mid = (s + en) / 2;

    if(pos <= mid){
        curr->right = pre->right;       // Save right side

        curr->left = new tree(NULL, NULL, 0);   // Create new left side

        update(pre->left, curr->left, s, mid, pos, val);    // Iterate
    }
    else{
        curr->left = pre->left;

        curr->right = new tree(NULL, NULL, 0);

        update(pre->right, curr->right, mid+1, en, pos, val);
    }

    curr->node = curr->left->node + curr->right->node;      // Save in *curr
return;
}

void PST::build_tree(struct tree *cur_root, int s, int e)
{
    if(s == e){
        cur_root->node = arr[s];
        return;
    }

    int mid = (s + e) / 2;
    cur_root->left = new tree(NULL, NULL, 0);
    cur_root->right = new tree(NULL, NULL, 0);

    build_tree(cur_root->left, s, mid);
    build_tree(cur_root->right, mid+1, e);

    cur_root->node = cur_root->left->node + cur_root->right->node;
return;
}

void PST::input_fun()
{
    int a[] = {1, 2, 3, 4, 5};

    int n = sizeof(a) / sizeof(int);

    for(int i=0; i<n; i++)
        arr[i] = a[i];

    root = new tree(NULL, NULL, 0);

    build_tree(root, 0, n-1);

    version[0] = root;

    version[1] = new tree(NULL, NULL, 0);
    update(version[0], version[1], 0, n-1, 4, 1);

    version[2] = new tree(NULL, NULL, 0);
    update(version[1], version[2], 0, n-1, 4, 1);

    cout<<quary(version[1], 0, n-1, 0, 4)<<endl;

    cout<<quary(version[2], 0, n-1, 3, 4)<<endl;

    cout<<quary(version[0], 0, n-1, 0, 3)<<endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    PST bc;
    bc.input_fun();
return 0;
}
