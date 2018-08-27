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
    struct tree *left,*right;
};

class BST{
    struct tree *root;
public:
    BST(){
        root = NULL;
    }
    void initializ(){

    }
    void input_fun();
    void insert_node(int n);
    void delete_node(int n);
    /*
        Search node in the tree.
    */
    bool find_node(int n);
    /*
        Calculate the size of a tree.
    */
    int size_of_tree(struct tree *cur_root);
    /*
        It check is a given Binary Tree is a Binary Search Tree or not.
    */
    bool BT_is_BST(struct tree *root, int minn, int maxx);
    /*
        It print in-order traversal of tree.
    */
    void print_inorder(struct tree *current_root);
};

bool BST::BT_is_BST(struct tree *cur_root, int minn, int maxx)
{
    if(cur_root == NULL) return true;

    if(cur_root->node >= minn  || cur_root->node < maxx)       // if outside the min max range
        return false;

    return BT_is_BST(cur_root->left, minn, cur_root->node);
    return BT_is_BST(cur_root->right, cur_root->node, maxx);
}

int BST::size_of_tree(struct tree * cur_root)
{
    if(cur_root == NULL)
        return 0;

    int leftt = size_of_tree(cur_root->left);
    int rightt = size_of_tree(cur_root->right);

    return leftt + rightt + 1;
}

void BST::insert_node(int n)
{
    if(root == NULL){
        root = (struct tree *)malloc(sizeof(struct tree));   // Make this the root node

        root->node = n;
        root->left = root->right = NULL;
        return;
    }

    struct tree **tmp_node = &root;

    while(*tmp_node != NULL){               // Find right place for the node
        if((*tmp_node)->node < n)
            tmp_node = &(*tmp_node)->right;
        else if((*tmp_node)->node >= n)
            tmp_node = &(*tmp_node)->left;
    }

    if(*tmp_node == NULL){
        *tmp_node = (struct tree *)malloc(sizeof(struct tree));
        (*tmp_node)->node = n;
        (*tmp_node)->left = (*tmp_node)->right = NULL;
        return;
    }
}

void BST::delete_node(int n)
{
    struct tree **tmp_root = &root;

    while(*tmp_root != NULL){
        if((*tmp_root)->node < n)
            tmp_root = &(*tmp_root)->right;

        else if((*tmp_root)->node > n)
            tmp_root = &(*tmp_root)->left;

        else if((*tmp_root)->node == n){

            if((*tmp_root)->left == NULL){              // If left is null put right at current root
                struct tree *d_n = (*tmp_root)->right;
                *tmp_root = d_n;
                d_n = NULL;
                return;
            }

            else if((*tmp_root)->right == NULL){        // If right is null put left at current root
                struct tree *d_n = (*tmp_root)->left;
                *tmp_root = d_n;
                d_n = NULL;
                return;
            }

            struct tree **n_tmp = &(*tmp_root)->right;

            if((*n_tmp)->left == NULL){             // If (node->right)->left == NULL
                (*n_tmp)->left = (*tmp_root)->left;     // (node->right)->left = current_root->left;
                *tmp_root = *n_tmp;                    // Now node->right is current_root
            }
            else{
                while((*n_tmp)->left != NULL)       // find The smallest node placed at most left of (node->right).
                    n_tmp = &(*n_tmp)->left;

                (*tmp_root)->node = (*n_tmp)->node;     // Make root value as that value
                *n_tmp = NULL;                          // Delete node
            }
            return;
        }
    }

    cout<<"Item not found!!!\a"<<endl;
return;
}

bool BST::find_node(int n)
{
    struct tree *tmp = root;

    while(tmp != NULL){
        if(tmp->node == n)
            return true;
        else if(tmp->node < n)
            tmp = tmp->right;
        else if(tmp->node > n){
            tmp = tmp->left;
        }
    }
return false;
}

void BST::print_inorder(struct tree *current_root)
{
    if(current_root == NULL)
        return;

    print_inorder(current_root->left);
    cout<<current_root->node<<"  ";
    print_inorder(current_root->right);
return;
}

void BST::input_fun()
{
    insert_node(5);
    insert_node(10);
    insert_node(3);
    insert_node(-5);
    insert_node(6);
    insert_node(4);

   // cout<<find_node(6)<<endl;

    cout<<"Size of The Tree : " << size_of_tree(root)<<endl;
    print_inorder(root);
    cout<<endl;

    delete_node(-5);
    print_inorder(root);
    cout<<endl;

    delete_node(5);

    print_inorder(root);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    BST bc;
    bc.input_fun();
return 0;
}
