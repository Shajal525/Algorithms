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

#define BLACK 3
#define RED 4
#define LEFT 1
#define RIGHT 2

//Template Ends Here

struct tree{
    int node,color,side_of_node;
    struct tree *left, *right, *parent;
};


class RBT{
    struct tree *root;
    bitset<MAX_VAL> visited;
public:
    void initializ(){}
    RBT(){ root = NULL; }
    void input_fun();

    struct tree* create_new_node(int nodee, int colorr){
        struct tree *tmp = (struct tree *)malloc(sizeof(struct tree));

        tmp->node = nodee;
        tmp->color = colorr;
        tmp->parent = tmp->left = tmp->right = NULL;

        return tmp;
    };

    void replace_node(struct tree *nodee, struct tree *chield);
    struct tree* sibling(struct tree* nodee);
    int left_or_right_ch(struct tree *node);

    void right_rotate(struct tree **root, struct tree *new_node, bool colorr);
    void left_rotate(struct tree **root, struct tree *new_node, bool colorr);

    void insertt(int node);
    void insertion_util(struct tree **cur_root, struct tree *new_node);
    void balance_RBT(struct tree **root, struct tree **new_node);

    struct tree* findd(struct tree *cur_root, int ind);
    struct tree* inorder_successor(struct tree* cur_root);

    void deletee(int ind);
    void deletion_util(struct tree **root, struct tree *node);
    void black_black_conditions(struct tree *black_black, struct tree **root);

    void inorder_tra(struct tree* cur_root);
    void level_order(struct tree* cur_root);
};

struct tree* RBT::sibling(struct tree* nodee)
{
     return nodee->parent->left == nodee ? nodee->parent->right : nodee->parent->left;
}

void RBT::replace_node(struct tree *nodee, struct tree *chield){
        struct tree *par = nodee->parent;

        if(par == NULL){
            chield->parent = NULL;
        }
        else if(left_or_right_ch(nodee) == LEFT){
            par->left = chield;

            if(par->left != NULL)
                par->left->parent = par;
        }
        else{
            par->right = chield;

            if(par->right != NULL)
                par->right->parent = par;
        }
        //  delete(nodee);
    }

void RBT::right_rotate(struct tree **root, struct tree *new_node, bool colorr)
{
    struct tree *par = new_node->parent;
    struct tree *gra_par = new_node->parent->parent;

    new_node->parent = gra_par;

    if(gra_par != NULL){
        if(left_or_right_ch(par) == LEFT)
            gra_par->left = new_node;

        else
            gra_par->right = new_node;
    }

    par->left = new_node->right;

    if(par->left != NULL)
        par->left->parent = par;

    new_node->right = par;

    new_node->right->parent = new_node;

    if(colorr)
        swap(new_node->color, par->color);

    if(par == *root)
        *root = new_node;

return;
}

void RBT::left_rotate(struct tree **root, struct tree *new_node, bool colorr)
{
    struct tree *par = new_node->parent;
    struct tree *gra_par = new_node->parent->parent;

    new_node->parent = gra_par;

    if(gra_par != NULL){
        if(left_or_right_ch(par) == LEFT)
            gra_par->left = new_node;

        else
            gra_par->right = new_node;
    }

    par->right = new_node->left;

    if(par->right != NULL)
        par->right->parent = par;

    new_node->left = par;

    new_node->left->parent = new_node;

    if(colorr)
        swap(new_node->color, par->color);

    if(par == *root)
        *root = new_node;
return;
}

int RBT::left_or_right_ch(struct tree *node)
{
    if(node->parent->left == node)
        return LEFT;
    else
        return RIGHT;
}

void RBT::balance_RBT(struct tree **cur_root, struct tree **new_node)
{
    while(*new_node != *cur_root && (*new_node)->color != BLACK && (*new_node)->parent->color == RED){

        struct tree *par = (*new_node)->parent;
        struct tree *gra_par = par->parent;

        struct tree *uncle = NULL;

        if(left_or_right_ch(par) == RIGHT){
            uncle = gra_par->left;

            if(uncle != NULL && uncle->color == RED){

                uncle->color = par->color = BLACK;
                gra_par->color = RED;

                new_node = &gra_par;
            }
            else{
                if(left_or_right_ch(*new_node) == LEFT){
                    right_rotate(cur_root, *new_node, false);
                }

                left_rotate(cur_root, par, true);
            }
        }
        else if(left_or_right_ch(par) == LEFT){
            uncle = gra_par->right;

            if(uncle != NULL && uncle->color == RED){

                uncle->color = par->color = BLACK;
                gra_par->color = RED;

                new_node = &gra_par;
            }
            else{
                if(left_or_right_ch(*new_node) == RIGHT){
                    left_rotate(cur_root, *new_node, false);
                }

                right_rotate(cur_root, par, true);
            }
        }
        (*cur_root)->color = BLACK;
    }
}

void RBT::insertion_util(struct tree **cur_root, struct tree *new_node)
{
    if(*cur_root == NULL){
        *cur_root = new_node;
        return;
    }
    else if((*cur_root)->node < new_node->node){
        insertion_util(&(*cur_root)->right, new_node);

        (*cur_root)->right->parent = *cur_root;
    }
    else{
        insertion_util(&(*cur_root)->left, new_node);

        (*cur_root)->left->parent = *cur_root;
    }
}

void RBT::insertt(int node)
{

    if(root == NULL){
        root = create_new_node(node, BLACK);
        return;
    }

    struct tree *new_node = create_new_node(node, RED);

    insertion_util(&root, new_node);

    balance_RBT(&root,  &new_node);
}

struct tree* RBT::findd(struct tree *cur_root, int ind)
{
    if(cur_root == NULL)
        return NULL;

    if(cur_root->node == ind)
        return cur_root;
    else if(cur_root->node < ind)
        return findd(cur_root->right, ind);
    else
        return findd(cur_root->left, ind);
}

struct tree* RBT::inorder_successor(struct tree* cur_root)
{
    if(cur_root->left == NULL)
        return cur_root;
    return inorder_successor(cur_root->left);
}

void RBT::black_black_conditions(struct tree *black_black, struct tree **root)
{
    while(1){
        // Case 1
        if(black_black->parent == NULL){
            *root = black_black;
            black_black->color = BLACK;
            break;
        }

        struct tree *uncle = NULL;

        // Case 2
        uncle = sibling(black_black);
        if(uncle != NULL && uncle->color == RED)
        {
            if(left_or_right_ch(uncle) == RIGHT){
                left_rotate(root, uncle, true);
            }
            else
                right_rotate(root, uncle, true);
        }

        // Case 3
        uncle = sibling(black_black);
        if(black_black->parent->color == BLACK && uncle->color == BLACK && (uncle->left == NULL || uncle->left->color == BLACK) &&
           (uncle->right == NULL || uncle->right->color == BLACK)){
            uncle->color = RED;

            black_black = black_black->parent;
            continue;
           }

        // Case 4
        uncle = sibling(black_black);
        if(black_black->parent->color == RED && uncle->color == BLACK && (uncle->left == NULL || uncle->left->color == BLACK) &&
           (uncle->right == NULL || uncle->right->color == BLACK)){
            uncle->color = RED;

            black_black->parent->color = BLACK;
            break;
           }

        // Case 5
        uncle = sibling(black_black);
        if(uncle->color == RED){
            if(left_or_right_ch(black_black) == LEFT && (uncle->right == NULL || uncle->right->color == BLACK) &&
               (uncle->left != NULL && uncle->left->color == RED)){
                    right_rotate(root, uncle->left, true);
               }
            else if(left_or_right_ch(black_black) == RIGHT && (uncle->left == NULL || uncle->left->color == BLACK) &&
               (uncle->right != NULL && uncle->right->color == RED)){
                    left_rotate(root, uncle->right, true);
               }
        }

        // Case 6
        uncle = sibling(black_black);
        uncle->color = uncle->parent->color;
        uncle->parent->color = BLACK;

        if(left_or_right_ch(black_black) == LEFT){
            uncle->right->color = BLACK;
            left_rotate(root, uncle, false);
        }
        else{
            uncle->left->color = BLACK;
            right_rotate(root, uncle, false);
        }
        break;
    }
return;
}

void RBT::deletion_util(struct tree **root, struct tree *nodee)
{
    struct tree *tmp = NULL;

    if(nodee->left != NULL && nodee->right != NULL){
        tmp = inorder_successor(nodee->right);

        nodee->node = tmp->node;

        deletion_util(root, tmp);
        return;
    }

    struct tree *chield = (nodee->right == NULL) ? nodee->left : nodee->right;

    replace_node(nodee, chield);    // If color of nodee is RED, just replace will do

    if(nodee->color == BLACK){
        if(chield == NULL){
            chield = create_new_node(INT_MIN, BLACK);
            chield->parent = nodee->parent;

            black_black_conditions(chield, root);

            if(left_or_right_ch(chield) == LEFT)
                chield->parent->left = NULL;
            else
                chield->parent->right = NULL;

            delete(chield);
        }
        else if(chield->color == RED){
            chield->color = BLACK;
        }
        else
            black_black_conditions(chield, root);
    }
}

void RBT::deletee(int index)
{
    struct tree *nodee = findd(root, index);

    deletion_util(&root, nodee);
}

void RBT::inorder_tra(struct tree* cur_root)
{
    if(cur_root == NULL)
        return;

    inorder_tra(cur_root->left);

    cout<<cur_root->node<<" ";

    inorder_tra(cur_root->right);
return;
}

void RBT::level_order(struct tree* cur_root)
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

void RBT::input_fun()
{
    insertt(7);
    insertt(6);
    insertt(5);
    insertt(4);
    insertt(3);
    insertt(2);
    insertt(1);

    deletee(7);

    inorder_tra(root);
    cout<<endl;

    level_order(root);

    cout<<endl;

return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    RBT bc;
    bc.input_fun();
return 0;
}
