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
     * If we are given in order and preorder traversal of a Binary tree or a BST and pre order traversal
     * The we can print post order traversal of that tree using. For BST if we sort the nodes we will get inorder traversal.
     * Time Complexity: O(N*N).
     * We can Build the tree using almost same method. Time comlpexity for building tree is also same
     * Time Complexity: O(N*N).
     * After building tree we can print any kind of traversal.
     *
     * If we are given inorder and post order traversal then what
     * This is same process but this time we need to do it revarce order for postorder array.
    */
    void input_fun();
    int search(int inOrd[], int st, int en, int val);
    void initializ_tree_array(int n);
    void print_traversal(struct tree* node);
    void print_traversal_using_array(int ind);
    void print_preOrder_to_postOrder_traversal(int inOrd[], int preOrd[], int n);
    tree* build_tree_using_pre_and_inorder_trav(int inOrd[], int preOrd[], int st, int en);
    void build_tree_using_pre_and_inorder_trav_array_imple(int inOrd[], int preOrd[], int st, int en, int tree_ind);

};

int CONVERSION::search(int inOrd[], int st, int en, int val)
{
    for(int i=st; i<=en; i++)
        if(inOrd[i] == val)
            return i;
    return -1;
}

void CONVERSION::initializ_tree_array(int n)
{
    for(int i=0; i<=2*n+8; i++)
        tree_array[i] = -1;
}

void CONVERSION::print_traversal_using_array(int ind)
{
    if(tree_array[ind] == -1)
        return;
    cout << tree_array[ind] << " ";
    print_traversal_using_array(left(ind));
    //cout << tree_array[ind] << " ";
    print_traversal_using_array(right(ind));
    //cout << tree_array[ind] << " ";0
}

void CONVERSION::print_traversal(tree *node)
{
    if(node == NULL)
        return;

    //cout << node->value << " ";
    print_traversal(node->left);
    //cout << node->value << " ";
    print_traversal(node->right);
    cout << node->value << " ";
}

// We can build tree using array.
void CONVERSION::build_tree_using_pre_and_inorder_trav_array_imple(int inOrd[], int preOrd[], int st, int en, int tree_ind)
{
    static int ind = 0; // Static value for calculating index of preOrder array.
    if(st > en)
        return;
    int val = preOrd[ind++];
    tree_array[tree_ind] = val; // Here we make the tree array.
    if(st == en)
        return;
    int found_ind = search(inOrd, st, en, val); // Search for val in inOrder array
    // Left subtree
    build_tree_using_pre_and_inorder_trav_array_imple(inOrd, preOrd, st, found_ind-1, left(tree_ind));
    // Right subtree
    build_tree_using_pre_and_inorder_trav_array_imple(inOrd, preOrd, found_ind+1, en, right(tree_ind));

    // We can also use the technic used in print_preOrder_to_postOrder_traversal().
}

// Here we build tree using linked list. Everything is almost same
tree* CONVERSION::build_tree_using_pre_and_inorder_trav(int inOrd[], int preOrd[], int st, int en)
{
    // If we are given postorder traversal then we need to start fron n-1 and ind++ each time
    static int ind = 0;
    if(st > en)
        return NULL;

    tree *node = new tree(preOrd[ind++]);   // ind-- for postorder array

    if(st == en)
        return node;

    int indof_val = search(inOrd, st, en, node->value);

    node->left = build_tree_using_pre_and_inorder_trav(inOrd, preOrd, st, indof_val-1);
    node->right = build_tree_using_pre_and_inorder_trav(inOrd, preOrd, indof_val+1, en);
    return node;
}

void CONVERSION::print_preOrder_to_postOrder_traversal(int inOrd[], int preOrd[], int n)
{
    if(n == 0)  // If this is leaf node
        return;
    int val = preOrd[0];            // First node in pre order traversal is root.
    int ind = search(inOrd, 0, n-1, val);    // Find first node in inorder traversal.
    // The left side of ind consists nodes of left subtree and right side consists nodes of right subtree
    // in both inorder and preorder array.

    print_preOrder_to_postOrder_traversal(inOrd, preOrd+1, ind);    // For left New n is ind and increase preOrd by 1

    //For right Number of node in right subtree is n-ind-1
    print_preOrder_to_postOrder_traversal(inOrd+ind+1, preOrd+ind+1, n-ind-1);

    cout << val << " "; // We can aslo store the traversal for later use.
}

void CONVERSION::input_fun()
{
    int in[] = {4, 2, 5, 1, 3, 6};
    int pre[] =  {1, 2, 4, 5, 3, 6};
    int n = sizeof(in)/sizeof(in[0]);
//    cout << "Postorder traversal " << endl;
//    print_preOrder_to_postOrder_traversal(in, pre, n);
//    cout << endl;

//    struct tree *head = build_tree_using_pre_and_inorder_trav(in, pre, 0, n-1);
//    cout << "In order traversal is: ";
//    print_traversal(head);
//    cout << endl;

    initializ_tree_array(n);
    build_tree_using_pre_and_inorder_trav_array_imple(in, pre, 0, n-1, 0);
    cout << "In order traversal is: ";
    print_traversal_using_array(0);
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

