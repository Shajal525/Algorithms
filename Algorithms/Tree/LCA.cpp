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
};


class LCA{
    struct tree *root;
public:
    LCA(){
        root = NULL;
    }
    void initializ(){

    }
    void input_fun();
    /*
        Find's Lowest Common Ancestor of two given node in Binary Search Tree.
    */
    int LCA_in_BST(struct tree *root, int l, int r);

    /*
        Find's Lowest Common Ancestor of two given node in normal Binary Tree.
    */
    struct tree* LCA_in_BT(struct tree *root, int l, int r);

    /*
        I will write that code later.
    */
    int LCA_using_RMQ();

    void insert_node(int n);
};

void LCA::insert_node(int n)
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

int LCA::LCA_in_BST(struct tree *root, int l, int r)
{
    if(root == NULL){
        cout<<"Error\a"<<endl;
        return -1;
    }

    if(root->node < l && root->node < r)
        return LCA_in_BST(root->right, l, r);

    else if(root->node > l && root->node > r)
        return LCA_in_BST(root->left, l, r);

    else return root->node;
}

struct tree* LCA::LCA_in_BT(struct tree *root, int l, int r)
{
    if(root == NULL)
        return NULL;

    if(root->node == l || root->node == r)
        return root;

    struct tree *leftt = LCA_in_BT(root->left, l, r);
    struct tree *rightt = LCA_in_BT(root->right, l, r);

    if(leftt != NULL && rightt != NULL)
        return root;

    else if(leftt == NULL && rightt == NULL)
        return NULL;

    return leftt == NULL ? rightt : leftt;
}

void LCA::input_fun()
{
    insert_node(5);
    insert_node(10);
    insert_node(3);
    insert_node(-5);
    insert_node(6);
    insert_node(4);

    cout<<LCA_in_BT(root, 3, 10)->node<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    LCA bc;
    bc.input_fun();
return 0;
}
