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

#define MAXV 1001
#define LEFT(x) 2*x+1
#define RIGHT(x) 2*x+2

struct Node{
    int val,index;
    Node(int x, int y):val(x),index(y){}
};


class TreeConversionBST{
    int bTree[2 * MAXV + 8];
public:
    /*
     * This is only for BST.
     * Tree Conversion usually takes O(N^2) time.
     * But for BST we can build tree in O(N) time.
     * This can be done in iterative and recursive method.
     * We will try both.
    */
    void initializ();
    void input_fun();
    void traversal(int ind);
    void build_tree(int traversal[], int n);
    void build_tree_from_preOrder(int pre[], int mn, int mx, int treeInd, int n);
    void build_tree_from_preOrder_iterative(int pre[], int n);
    void build_tree_from_postOrder(int pre[], int mn, int mx, int treeInd, int n);
    void build_tree_from_postOrder_iterative(int post[], int n);
};

void TreeConversionBST::initializ()
{
    for(int i=0; i<2*MAXV+5; i++)
        bTree[i] = INT_MIN;
}

void TreeConversionBST::traversal(int ind)
{
    if(bTree[ind] == INT_MIN)
        return;

    //cout << bTree[ind] << " ";
    traversal(2*ind+1);
    //cout << bTree[ind] << " ";
    traversal(2*ind+2);
    cout << bTree[ind] << " ";
}

void TreeConversionBST::build_tree_from_preOrder(int pre[], int mn, int mx, int treeInd, int n)
{
    static int preInd = 0;
    if(preInd >= n) // Base case
        return;

    int key = pre[preInd];  // This is the key
    if(key > mn && key < mx){
        preInd++;   // This is very importent. We can only update preInd only if we can enter this if block.

        build_tree_from_preOrder(pre, mn, key, LEFT(treeInd), n); // We must check Left first
        build_tree_from_preOrder(pre, key, mx, RIGHT(treeInd), n); // Check right

        bTree[treeInd] = key;   // Submit in bTree
    }
    return;
}

void TreeConversionBST::build_tree_from_preOrder_iterative(int pre[], int n)
{
    stack<Node> stk;
    bTree[0] = pre[0];  // pre[0] is root
    stk.push(Node(pre[0], 0));  // Push root and its index in stack

    for(int i=1; i<n; i++){ // For every node
        int node = INT_MIN; // Initializ node
        int val = pre[i];   // This node

        // If val is greater then stk.top().val then we go up in the tree by poping from stack
        while(!stk.empty() && val > stk.top().val){
            node = stk.top().index;
            stk.pop();
        }

        // If node is INT_MIN that means val is less then stk.top().val So we add in left side
        if(node == INT_MIN){
            int ind = stk.top().index;
            bTree[LEFT(ind)] = val;
            stk.push(Node(val, LEFT(ind))); // Push this node with index
        }
        else{   // val is greater then stk.top().val at least once. So last small node in stk which is less then val is 'node'
            bTree[RIGHT(node)] = val;   // Add val in Right of 'node'
            stk.push(Node(val, RIGHT(node)));
        }
    }
    return;
}


void TreeConversionBST::build_tree_from_postOrder(int post[], int mn, int mx, int treeInd, int n)
{
    static int postInd = n-1;   // Start here because this is the root of our tree
    if(postInd < 0) // Base case
        return;

    int key = post[postInd];  // This is the key
    if(key > mn && key < mx){
        postInd--;   // This is very importent. We can only update postInd only if we can enter this if block.

        build_tree_from_postOrder(post, key, mx, RIGHT(treeInd), n); // We must check Right side first
        build_tree_from_postOrder(post, mn, key, LEFT(treeInd), n); // Then Check left

        bTree[treeInd] = key;   // Submit in bTree
    }
    return;
}

void TreeConversionBST::build_tree_from_postOrder_iterative(int post[], int n)
{
    stack<Node> stk;
    bTree[0] = post[n-1];  // post[n-1] is root
    stk.push(Node(post[n-1], 0));  // Push root and its index in stack

    for(int i=n-2; i>=0; i--){ // We check in reverse order
        int node = INT_MIN; // Initializ node
        int val = post[i];   // This node

        // If val is less then stk.top().val then we go up in the tree by poping from stack
        while(!stk.empty() && val < stk.top().val){
            node = stk.top().index;
            stk.pop();
        }

        // If node is INT_MIN that means val is greater then stk.top().val So we add in RIGHT side
        if(node == INT_MIN){
            int ind = stk.top().index;
            bTree[RIGHT(ind)] = val;
            stk.push(Node(val, RIGHT(ind))); // Push this node with index
        }
        else{   // val is less then stk.top().val at least once. So last node in stk which is greater then val is 'node'
            bTree[LEFT(node)] = val;   // Add val in Left of 'node'
            stk.push(Node(val, LEFT(node)));
        }
    }
    return;
}

void TreeConversionBST::build_tree(int traversal[], int n)
{
    //build_tree_from_preOrder(traversal, INT_MIN, INT_MAX, 0, n);
    //build_tree_from_preOrder_iterative(traversal, n);
    //build_tree_from_postOrder(traversal, INT_MIN, INT_MAX, 0, n);
    build_tree_from_postOrder_iterative(traversal, n);
    return;
}

void TreeConversionBST::input_fun()
{
//    int pre[] = {10, 5, 1, 7, 40, 50};
//    int n = sizeof(pre)/ sizeof(pre[0]);

//    initializ();
//    build_tree(pre, n);
//    traversal(0);
//    cout << endl;

    int post[] = {1, 7, 5, 50, 40, 10};
    int n = sizeof(post) / sizeof(post[0]);

    initializ();
    build_tree(post, n);
    traversal(0);
    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    TreeConversionBST bc;
    bc.input_fun();
return 0;
}

