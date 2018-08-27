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
    int node,height;
    struct tree *left,*right;
};

class AVL{
    struct tree *root;
public:
    AVL(){
        root = NULL;
    }
    void initializ(){

    }
    void input_fun();

    struct tree* create_node(int n, int h){
        struct tree *nodee = (struct tree* )malloc(sizeof(struct tree));

        nodee->node = n;
        nodee->height = h;
        nodee->left = nodee->right = NULL;

        return nodee;
    };

    int height_of(struct tree *nodee){
        if( nodee == NULL)
            return 0;
        return nodee->height;
    }

    void left_left_rotate(struct tree **current_root);

    void right_right_rotate(struct tree **current_root);

    void left_right_rotate(struct tree **current_root);

    void right_left_rotate(struct tree **current_root);

    void balance_height(struct tree **cur_root);

    void insert_node(struct tree **cur_root, int n);

    /*
        This will be used for deleting a node.
    */
    void delete_node(struct tree **cur_root, int n);
    /*
        Search node in the tree.
    */
    bool find_node(int n);
    /*
        Calculate the size of a tree.
    */
    int size_of_tree(struct tree *cur_root);
    /*
        It print in-order traversal of tree.
    */
    void print_inorder(struct tree *current_root);

    void print_preorder(struct tree *current_root);
};

void AVL::left_left_rotate(struct tree **current_root)
{
    struct tree *new_root = (*current_root)->left;

    (*current_root)->left = new_root->right;

    new_root->right = *current_root;

    *current_root = new_root;

    new_root->left->height = 1 + max(height_of(new_root->left->left), height_of(new_root->left->right));
    new_root->right->height = 1 + max(height_of(new_root->right->left), height_of(new_root->right->right));
return;
}

void AVL::left_right_rotate(struct tree **current_root)
{
    struct tree *new_root = ((*current_root)->left)->right;

    (*current_root)->left->right = new_root->left;

    new_root->left = (*current_root)->left;

    (*current_root)->left = new_root;

return;
}

void AVL::right_right_rotate(struct tree **current_root)
{
    struct tree *new_root = (*current_root)->right;

    (*current_root)->right = new_root->left;

    new_root->left = *current_root;

    *current_root = new_root;

    new_root->left->height = 1 + max(height_of(new_root->left->left), height_of(new_root->left->right));
    new_root->right->height = 1 + max(height_of(new_root->right->left), height_of(new_root->right->right));
return;
}

void AVL::right_left_rotate(struct tree **current_root)
{
    struct tree *new_root = (*current_root)->right->left;

    (*current_root)->right->left = new_root->right;

    new_root->right = (*current_root)->right;

    (*current_root)->right = new_root;
return;
}

void AVL::balance_height(struct tree **cur_root)
{
    int balance = height_of((*cur_root)->left) - height_of((*cur_root)->right);  // AVL balancing starts here.

    if(balance > 1){
        struct tree *tmp = (*cur_root)->left;

        if(height_of(tmp->left) >= height_of(tmp->right)){
            left_left_rotate(cur_root);
        }

        else {
            left_right_rotate(cur_root);
            left_left_rotate(cur_root);
        }
    }

    if(balance < -1){
        struct tree *tmp = (*cur_root)->right;

        if(height_of(tmp->left) <= height_of(tmp->right)){
            right_right_rotate(cur_root);
        }

        else {
            right_left_rotate(cur_root);
            right_right_rotate(cur_root);
        }
    }

    (*cur_root)->height = 1 + max(height_of((*cur_root)->left), height_of((*cur_root)->right));
return;
}

int AVL::size_of_tree(struct tree * cur_root)
{
    if(cur_root == NULL)
        return 0;

    int leftt = size_of_tree(cur_root->left);
    int rightt = size_of_tree(cur_root->right);

    return leftt + rightt + 1;
}

void AVL::insert_node(struct tree **cur_root, int n)
{
    if(*cur_root == NULL){               // Normal BST insertion Start here.
        *cur_root = create_node(n, 1);   // Create tree node with node = n and height = 0.

        return;
    }

    if((*cur_root)->node < n)
        insert_node(&(*cur_root)->right, n);

    else if((*cur_root)->node >= n)
        insert_node(&(*cur_root)->left, n);    // Normal BST insertion Ends here.

    balance_height(cur_root);
}

void AVL::delete_node(struct tree **cur_root, int n)
{
    if(*cur_root == NULL)
        return;

    bool done = false;

    if((*cur_root)->node < n)
        delete_node(&(*cur_root)->right, n);

    else if((*cur_root)->node > n)
        delete_node(&(*cur_root)->left, n);

    else if((*cur_root)->node == n){

        if((*cur_root)->left == NULL){              // If left is null put right at current root
            struct tree *d_n = (*cur_root)->right;
            *cur_root = d_n;
            done = true;
        }

        else if((*cur_root)->right == NULL){        // If right is null put left at current root
            struct tree *d_n = (*cur_root)->left;
            *cur_root = d_n;
            d_n = NULL;
            done = true;
        }

        struct tree **n_tmp = &(*cur_root)->right;

        if(!done && (*n_tmp)->left == NULL){             // If (node->right)->left == NULL
            (*n_tmp)->left = (*cur_root)->left;     // (node->right)->left = current_root->left;
            *cur_root = *n_tmp;                    // Now node->right is current_root
        }
        else if(!done){
            while((*n_tmp)->left != NULL)       // find The smallest node placed at most left of (node->right).
                n_tmp = &(*n_tmp)->left;

                (*cur_root)->node = (*n_tmp)->node;     // Make root value as that value
                *n_tmp = (*n_tmp)->right;                          // Delete node
        }
    }

    balance_height(cur_root);
 return;
}

bool AVL::find_node(int n)
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

void AVL::print_preorder(struct tree *current_root)
{
    if(current_root == NULL)
        return;

    cout<<current_root->node<<"  ";
    print_preorder(current_root->left);
    print_preorder(current_root->right);
return;
}

void AVL::print_inorder(struct tree *current_root)
{
    if(current_root == NULL)
        return;

    print_inorder(current_root->left);
    cout<<current_root->node<<"  ";
    print_inorder(current_root->right);
return;
}

void AVL::input_fun()
{
    insert_node(&root, 9);
    insert_node(&root, 5);
    insert_node(&root, 10);
    insert_node(&root, 0);
    insert_node(&root, 6);
    insert_node(&root, 11);
    insert_node(&root, -1);
    insert_node(&root, 1);
    insert_node(&root, 2);

    print_preorder(root);
    cout<<endl<<endl;

    delete_node(&root, 10);

    print_preorder(root);
    cout<<endl;

   // cout<<find_node(6)<<endl;

//    cout<<root->node<<" "<<root->left->node<<" "<<root->right->node<<endl;

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    AVL bc;
    bc.input_fun();
return 0;
}

