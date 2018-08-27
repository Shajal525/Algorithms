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
    tree(int n){
        left = right = NULL;
        node = n;
    }
};

class SPLAY{
    //struct tree *root;
public:
    SPLAY(){
     //   root = NULL;
    }
    void initializ(){}
    void input_fun();
    struct tree* right_rotate(struct tree *root);
    struct tree* left_rotate(struct tree *root);
    void inorder_tra(struct tree* cur_root);
    void level_order(struct tree* cur_root);
    void preorder_tra(struct tree* cur_root);
    struct tree* inorder_successor(struct tree *tmp, struct tree *roott);

    struct tree* insertt(struct tree *roott, int node);

    struct tree* findd(struct tree *roott, int n);

    struct tree* deletee(struct tree *roott, int n);

    struct tree* splayy(struct tree *roott, int key);

};

struct tree* SPLAY::right_rotate(struct tree *x)
{
    struct tree *y = x->left;
    if(y == NULL)
        return x;
    x->left = y->right;
    y->right = x;
    return y;
}

struct tree* SPLAY::left_rotate(struct tree *x)
{
    struct tree *y = x->right;
    if(y == NULL)
        return x;
    x->right = y->left;
    y->left = x;
    return y;
}

struct tree* SPLAY::splayy(struct tree *roott, int key)
{
    if(roott == NULL || roott->node == key)
        return roott;

    if(roott->node > key){
        if(roott->left == NULL)
                return roott;

        if(roott->left->node > key){
            roott->left->left = splayy(roott->left->left, key);

            roott = right_rotate(roott);
        }
        else if(roott->left->node < key){
            roott->left->right = splayy(roott->left->right, key);

          //  if(roott->left->right != NULL)
            roott->left = left_rotate(roott->left);
        }

        return right_rotate(roott);
    }

    else{
        if(roott->right == NULL)
            return roott;

        if(roott->right->node < key){
            roott->right->right = splayy(roott->right->right, key);

            roott = left_rotate(roott);
        }
        else if(roott->right->node > key){
            roott->right->left = splayy(roott->right->left, key);

            roott->right = right_rotate(roott->right);
        }

        return left_rotate(roott);
    }
}


void SPLAY::inorder_tra(struct tree* cur_root)
{
    if(cur_root == NULL)
        return;

    inorder_tra(cur_root->left);

    cout<<cur_root->node<<" ";

    inorder_tra(cur_root->right);
return;
}

void SPLAY::preorder_tra(struct tree* cur_root)
{
    if(cur_root == NULL)
        return;

    cout<<cur_root->node<<" ";

    preorder_tra(cur_root->left);

    preorder_tra(cur_root->right);
return;
}

void SPLAY::level_order(struct tree* cur_root)
{
    queue<struct tree*> qu;
    qu.push(cur_root);

    while(!qu.empty()){
        struct tree *tmp = qu.front();
        qu.pop();

        cout<<tmp->node<<" ";

        if(tmp->left != NULL) qu.push(tmp->left);
        if(tmp->right != NULL) qu.push(tmp->right);
    }
return;
}

struct tree* SPLAY::findd(struct tree *roott, int key)
{
    return splayy(roott, key);
}

struct tree* SPLAY::insertt(struct tree *roott, int key)
{
    if(roott == NULL)
        return new tree(key);

    roott = splayy(roott, key);

    if(roott->node == key)
        return roott;

    struct tree *new_node = new tree(key);

    if(roott->node > key){
        new_node->right = roott;
        new_node->left = roott->left;
        roott->left = NULL;
    }
    else{
        new_node->left = roott;
        new_node->right = roott->right;
        roott->right = NULL;
    }

return new_node;
}

struct tree* SPLAY::inorder_successor(struct tree *tmp, struct tree *roott)
{
    if(tmp->left == NULL)
    {
        roott->node = tmp->node;
        return tmp->right;
    }
    else{
        tmp->left = inorder_successor(tmp->left, roott);
        return tmp;
    }
}

struct tree* SPLAY::deletee(struct tree* roott, int key)
{
    if(roott == NULL || roott->node == key)
        return roott=NULL;
    roott = splayy(roott, key);

    if(roott->node != key)
        return roott;

    if(roott->left == NULL && roott->right == NULL)
        return roott = NULL;
    else if(roott->left == NULL){
        struct tree *nn = roott->right;
        roott = NULL;
        return nn;
    }
    else if(roott->right == NULL){
        struct tree *nn = roott->left;
        roott = NULL;
        return nn;
    }
    else{
        struct tree *tmp = roott->right;

        if(tmp->left == NULL){
            tmp->left = roott->left;
            roott = NULL;
            return tmp;
        }

        tmp = inorder_successor(tmp, roott);
        return roott;
    }
return roott;
}

void SPLAY::input_fun()
{
    struct tree *root = new tree(100);
    root->left = new tree(50);
    root->right = new tree(200);
    root->left->left = new tree(40);
    root->left->left->left = new tree(30);
    root->left->left->left->left = new tree(20);

    root  = insertt(root, 25);

    root  = deletee(root, 30);

    preorder_tra(root);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    SPLAY bc;
    bc.input_fun();
return 0;
}
