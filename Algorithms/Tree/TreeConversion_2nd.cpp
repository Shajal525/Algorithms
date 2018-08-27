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
#define MAXV 1009
struct tree{
    int value;
    struct tree *left, *right;
    tree(int val){
        value = val;
        left = NULL;
        right = NULL;
    }
};


int tree_array[2*MAXV + 88];

int left(int n)
{
    return 2*n+1;
}
int right(int n)
{
    return 2*n+2;
}

class CONVERSION{
public:
    /*
     * Builds Full Binary Tree from given preOrder and postOrder traversal.
     * This is only possible if Binary tree is full.
     * Time Complexity: O(N*N).
     *
     * Building binary tree from given inOrder and levelOrder traversal.
     * Time Complexity: O(N^3).
    */
    void input_fun();
    int search(int postOrd[], int st, int en, int val);
    void print_traversal(struct tree* node);
    tree* build_tree_from_pre_and_postOrder(int postOrd[], int preOrd[], int st, int en, int size);
    tree* build_tree_from_in_and_levelOrder(int inOrd[], int levelOrd[], int st, int en, int size);
    int* extrackKeys(int in[], int level[], int m, int n);
};

int CONVERSION::search(int postOrd[], int st, int en, int val)
{
    for(int i=st; i<=en; i++)
        if(postOrd[i] == val)
            return i;
    return -1;
}

int* CONVERSION::extrackKeys(int in[], int level[], int m, int n)
{
    int *newlevel = new int[m], j = 0;
    // Find each node of levelOrder array in inOrder array.
    // If found then we take that node and add it in new array.
    for (int i = 0; i < n; i++)
        if (search(in, 0, m-1, level[i]) != -1)
            newlevel[j] = level[i], j++;
    return newlevel;
}

void CONVERSION::print_traversal(tree *node)
{
    if(node == NULL)
        return;

    //cout << node->value << " ";
    print_traversal(node->left);
    cout << node->value << " ";
    print_traversal(node->right);
    //cout << node->value << " ";
}

tree* CONVERSION::build_tree_from_in_and_levelOrder(int inOrd[], int levelOrd[], int st, int en, int size)
{
    if(st > en)
        return NULL;
    tree *root = new tree(levelOrd[0]); // Each time we are using 0th node.

    if(st == en)
        return root;

    int ind = search(inOrd, st, en, root->value);

    // From 0 to ind all nodes are in left tree. So now we need to make new levelOrder array of node in left subtree
    int *left = extrackKeys(inOrd, levelOrd, ind, size);
    // Search for nods in right subtree and make new levelOrder array for right subtree.
    int *right = extrackKeys(inOrd + ind +1, levelOrd, en-ind, size);

    root->left = build_tree_from_in_and_levelOrder(inOrd, left, st, ind-1, size);

    root->right = build_tree_from_in_and_levelOrder(inOrd, right, ind+1, en, size);

    delete [] left;
    delete [] right;
    return root;
}

tree* CONVERSION::build_tree_from_pre_and_postOrder(int postOrd[], int preOrd[], int st, int en, int size)
{
    static int pre_ind = 0;
    if(pre_ind >= size || st > en)
        return NULL;

    tree *root = new tree(preOrd[pre_ind++]);   // First node of preOrder traversal is root

    if(st == en)
        return root;

    int ind = search(postOrd, st, en, preOrd[pre_ind]); // Search for next node of root in postOrder traversal

    if(ind != -1 && ind <= en){  // If found. This condition is must
        // Bear in mind ind is also in left subtree. So we must use ind. Not ind-1
        root->left = build_tree_from_pre_and_postOrder(postOrd, preOrd, st, ind, size);

        root->right = build_tree_from_pre_and_postOrder(postOrd, preOrd, ind+1, en, size);
    }
    return root;
}

void CONVERSION::input_fun()
{
//    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
//    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
//    int n = sizeof(post)/sizeof(post[0]);
//    tree *node = build_tree_from_pre_and_postOrder(post, pre, 0, n-1, n);
//    cout << "InOrder Traversal: ";
//    print_traversal(node);
//    cout << endl;

    int in[]    = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(in)/sizeof(in[0]);
    struct tree *root = build_tree_from_in_and_levelOrder(in, level, 0, n - 1, n);

    /* Let us test the built tree by printing Insorder traversal */
    cout << "Inorder traversal of the constructed tree is: ";
    print_traversal(root);
    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    CONVERSION bc;
    bc.input_fun();
return 0;
}

