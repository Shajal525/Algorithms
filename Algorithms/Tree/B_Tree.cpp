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
#define MAX_child 5
#define T (MAX_child/2)
//int SET(int n,int i) {return (n|(1<<i));}
//int RESET(int n,int i) {return (n&~(1<<i));}
//bool check(int n,int i) {return (n&(1<<i));}
using namespace std;

//Template Ends Here

struct tree{
    int key[MAX_child];
    struct tree *child[MAX_child+1];
    bool is_leaf;
    int num_of_node;
    tree(){
        this->num_of_node = 0;
        this->is_leaf = true;
        for(int i=0; i<=MAX_child+1; i++)
            this->child[i] = NULL;
    }

    tree(int num, bool f){
        this->num_of_node = num;
        this->is_leaf = f;
        for(int i=0; i<=MAX_child+1; i++)
            this->child[i] = NULL;
    }
};


class B_TREE{
    struct tree* root;
public:
    B_TREE(){
        root = NULL;
    }
    void input_fun();

    void traverse(struct tree *cur_root);

    struct tree* searchh(struct tree *cur_root, int key);

    void removee(struct tree *&cur_root, int key);
    void rem_from_leaf(struct tree *&cur_root, int ind);
    void rem_from_non_leaf(struct tree *&cur_root, int ind);
    int get_pred(struct tree *&cur_root, int ind);
    int get_succ(struct tree *&cur_root, int ind);
    void filll(struct tree *&cur_root, int ind);
    void borrow_from_prev(struct tree *&cur_root, int ind);
    void borrow_from_next(struct tree *&cur_root, int ind);
    void mergee(struct tree *&cur_root, int ind);
    int find_ind(struct tree *&cur_root, int key);


    void split_child(struct tree *&thiss, struct tree *&par);
    void insertInNonFull(struct tree *&thiss, int key);
    void insertt(struct tree *&cur_root, int key);
    /*
        Reference : geeksforgeeks.com
    */
};

int B_TREE::find_ind(struct tree *&cur_root, int key)
{
    int ind = 0;
    int n = cur_root->num_of_node;
    while(ind < n && cur_root->key[ind] < key)
        ++ind;
    return ind;
}

void B_TREE::rem_from_leaf(struct tree *&cur_root, int ind)
{
    for(int i = ind+1; i<cur_root->num_of_node; i++)
        cur_root->key[i-1] = cur_root->key[i];
    cur_root->num_of_node -= 1;
return;
}

void B_TREE::rem_from_non_leaf(struct tree *&cur_root, int ind)
{
    int k = cur_root->key[ind];

    if(cur_root->child[ind]->num_of_node >= T)
    {
        int pred = get_pred(cur_root, ind);
        cur_root->key[ind] = pred;

        removee(cur_root->child[ind], pred);
    }

    else if(cur_root->child[ind+1]->num_of_node >= T)
    {
        int succ = get_succ(cur_root, ind);
        cur_root->key[ind] = succ;

        removee(cur_root->child[ind+1], succ);
    }

    else
    {
        mergee(cur_root, ind);
        removee(cur_root->child[ind], k);
    }
return;
}

int B_TREE::get_pred(struct tree *&cur_root, int ind)
{
    struct tree *cur = cur_root->child[ind];
    while(!cur->is_leaf)
        cur = cur->child[cur->num_of_node];

    return cur->key[cur->num_of_node-1];
}

int B_TREE::get_succ(struct tree *&cur_root, int ind)
{
    struct tree *cur = cur_root->child[ind+1];
    while(!cur->is_leaf)
        cur = cur->child[0];

    return cur->key[0];
}

void B_TREE::filll(struct tree *&cur_root, int ind)
{
    if(ind != 0 && cur_root->child[ind-1]->num_of_node >= T)
        borrow_from_prev(cur_root, ind);

    else if(ind != cur_root->num_of_node && cur_root->child[ind+1]->num_of_node >= T)
        borrow_from_next(cur_root, ind);

    else
    {
        if(ind != cur_root->num_of_node)
            mergee(cur_root, ind);
        else
            mergee(cur_root, ind-1);
    }
return;
}

void B_TREE::borrow_from_prev(struct tree *&cur_root, int ind)
{
    struct tree *child = cur_root->child[ind];
    struct tree *sibling = cur_root->child[ind-1];

    for(int i=child->num_of_node-1; i>=0; i--)
        child->key[i+1] = child->key[i];

    if(!child->is_leaf)
    {
        for(int i=child->num_of_node; i>=0; i--)
            child->child[i+1] = child->child[i];
    }

    child->key[0] = cur_root->key[ind-1];

    if(!cur_root->is_leaf)
        child->child[0] = sibling->child[sibling->num_of_node];

    cur_root->key[ind-1] = sibling->key[sibling->num_of_node-1];

    child->num_of_node += 1;
    sibling->num_of_node -= 1;
return;
}

void B_TREE::borrow_from_next(struct tree *&cur_root, int ind)
{
    struct tree *child = cur_root->child[ind];
    struct tree *sibling = cur_root->child[ind+1];

    child->key[child->num_of_node] = cur_root->key[ind];

    if(!child->is_leaf)
        child->child[child->num_of_node+1] = sibling->child[0];

    cur_root->key[ind] = sibling->key[0];

    for(int i=1; i<sibling->num_of_node; i++)
        sibling->key[i-1] = sibling->key[i];

    if(!sibling->is_leaf)
    {
        for(int i=1; i<=sibling->num_of_node; i++)
            sibling->child[i-1] = sibling->child[i];
    }

    child->num_of_node+= 1;
    sibling->num_of_node -= 1;
return;
}

void B_TREE::mergee(struct tree *&cur_root, int ind)
{
    struct tree *child = cur_root->child[ind];
    struct tree *sibling = cur_root->child[ind+1];

    child->key[T-1] = cur_root->key[ind];

    for (int i=0; i<sibling->num_of_node; ++i)
        child->key[i+T] = sibling->key[i];

    if (!child->is_leaf)
    {
        for(int i=0; i<=sibling->num_of_node; ++i)
            child->child[i+T] = sibling->child[i];  // Some confusion( I think another merge required)
    }

    for (int i=ind+1; i<cur_root->num_of_node; ++i)
        cur_root->key[i-1] = cur_root->key[i];

    for (int i=ind+2; i<=cur_root->num_of_node; ++i)
        cur_root->child[i-1] = cur_root->child[i];

    child->num_of_node += sibling->num_of_node+1;
    cur_root->num_of_node--;

    delete(sibling);
    return;
}

void B_TREE::removee(struct tree *&cur_root, int key)
{
    int ind = find_ind(cur_root, key);

    if(ind < cur_root->num_of_node && cur_root->key[ind] == key)
    {
        if(cur_root->is_leaf == true)
            rem_from_leaf(cur_root, ind);
        else
            rem_from_non_leaf(cur_root, ind);
    }
    else
    {
        if(cur_root->is_leaf == true)
        {
            cout << "The Key " << key << "is not exist in this tree" << endl;
            return;
        }

        bool flag = (cur_root->num_of_node == ind) ? true : false;

        if(cur_root->child[ind]->num_of_node < T)
            filll(cur_root, ind);

        if(flag && ind > cur_root->num_of_node)
            removee(cur_root->child[ind-1], key);
        else
            removee(cur_root->child[ind], key);
    }
return;
}

void B_TREE::traverse(struct tree *cur_root)
{
    if(cur_root == NULL)
        return;

    int n = cur_root->num_of_node;
    for(int i=0; i<n; i++){
       // cout<<cur_root->key[i]<<" ";
        if(cur_root->is_leaf == false)
            traverse(cur_root->child[i]);
        cout<<cur_root->key[i]<<" ";
    }

    if(cur_root->is_leaf == false)
        traverse(cur_root->child[n]);
}

struct tree* B_TREE::searchh(struct tree *cur_root, int key)
{
    int n = cur_root->num_of_node;
    int i=0;
    while(i < n && cur_root->key[i] > key)
        i++;
    if(cur_root->key[i] == key)
        return cur_root;

    if(cur_root->is_leaf == true)
        return NULL;

    return searchh(cur_root->child[i], key);
}



void B_TREE::split_child(struct tree *&thiss, struct tree *&par)
{
    int i,j;
    struct tree *left = new tree(0, true);
    struct tree *right = new tree(0, true);
    left->is_leaf = thiss->is_leaf;
    right->is_leaf = thiss->is_leaf;

    for(i=0; i<MAX_child/2; i++){
        left->key[i] = thiss->key[i];
        left->child[i] = thiss->child[i];
    }
    left->child[i] = thiss->child[i];
    left->num_of_node = i;

    for(i=0, j = (MAX_child/2)+1; j<MAX_child; j++,i++){
        right->key[i] = thiss->key[j];
        right->child[i] = thiss->child[j];
    }
    right->child[i] = thiss->child[j];
    right->num_of_node = i;

    if(par == NULL){
        struct tree *new_root = new tree(0, false);
        new_root->key[0] = thiss->key[MAX_child / 2];
        new_root->num_of_node = 1;
        new_root->child[0] = left;
        new_root->child[1] = right;
        thiss = new_root;
    }
    else{
        int nn = thiss->key[MAX_child/2];
        i = par->num_of_node - 1;
        while(i >=0 && par->key[i] > nn)
        {
            par->key[i+1] = par->key[i];
            par->child[i+2] = par->child[i+1];
            i--;
        }
        i++;
        par->key[i] = nn;
        par->child[i] = left;
        par->child[i+1] = right;
        par->num_of_node += 1;
    }

//    return new_root;
}

void B_TREE::insertInNonFull(struct tree *&thiss, int key)
{
    int n = thiss->num_of_node;
    int i = n-1;
    if(thiss->is_leaf == true){
        while(i >= 0 && thiss->key[i] > key){
            thiss->key[i+1] = thiss->key[i];
            i--;
        }
        thiss->key[i+1] = key;
        thiss->num_of_node++;
    }
    else{
        bool spl = false;
        while(i >= 0 && thiss->key[i] > key)
            i--;
        i++;

        if(thiss->child[i] == NULL){
            thiss->child[i] = new tree(0, true);
        }
        else if(thiss->child[i]->num_of_node == MAX_child)
        {
            split_child(thiss->child[i], thiss);
            spl = true;
        }
        if(spl)
            insertInNonFull(thiss, key);
        else
            insertInNonFull(thiss->child[i], key);
    }
}

void B_TREE::insertt(struct tree *&cur_root, int key)
{
    if(cur_root == NULL){
        cur_root = new tree(0, true);
        cur_root->is_leaf = true;
        cur_root->num_of_node += 1;
        cur_root->key[0] = key;
    }
    else{
        if(cur_root->num_of_node == MAX_child){
            struct tree *par = NULL;
            split_child(cur_root, par);
        }

        insertInNonFull(cur_root, key);
    }

}

void B_TREE::input_fun()
{
    insertt(root, 1);
    insertt(root, 3);
    insertt(root, 7);
    insertt(root, 10);
    insertt(root, 11);
    insertt(root, 13);
    insertt(root, 14);
    insertt(root, 15);
    insertt(root, 18);
    insertt(root, 16);
    insertt(root, 19);
    insertt(root, 24);
    insertt(root, 25);
    insertt(root, 26);
    insertt(root, 21);
    insertt(root, 4);
    insertt(root, 5);
    insertt(root, 20);
    insertt(root, 22);
    insertt(root, 2);
    insertt(root, 17);
    insertt(root, 12);
    insertt(root, 6);

    cout << "Traversal of tree constructed is\n";
    traverse(root);
    cout << endl;

    removee(root, 6);
    cout << "Traversal of tree after removing 6\n";
    traverse(root);
    cout << endl;

    removee(root, 13);
    cout << "Traversal of tree after removing 13\n";
    traverse(root);
    cout << endl;

    removee(root, 7);
    cout << "Traversal of tree after removing 7\n";
    traverse(root);
    cout << endl;

    removee(root, 4);
    cout << "Traversal of tree after removing 4\n";
    traverse(root);
    cout << endl;

    removee(root, 2);
    cout << "Traversal of tree after removing 2\n";
    traverse(root);
    cout << endl;

    removee(root, 16);
    cout << "Traversal of tree after removing 16\n";
    traverse(root);
    cout << endl;

    return;

//    insertt(root, 10);
//    insertt(root, 20);
//    insertt(root, 5);
//    insertt(root, 6);
//    insertt(root, 1);
//    insertt(root, 2);
//    insertt(root, 3);
//    insertt(root, 4);
//    insertt(root, 50);
//    insertt(root, 12);
//    insertt(root, 30);
//    insertt(root, 7);
//    insertt(root, 17);
//    insertt(root, 3);
//
//
//    traverse(root);
//    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    B_TREE bt;
    bt.input_fun();
}

