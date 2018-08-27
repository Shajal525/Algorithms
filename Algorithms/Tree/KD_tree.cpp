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
#define DIMENSION 2
//int SET(int n,int i) {return (n|(1<<i));}
//int RESET(int n,int i) {return (n&~(1<<i));}
//bool check(int n,int i) {return (n&(1<<i));}
using namespace std;
struct tree *nul = NULL;

//Template Ends Here

struct tree{
    int arr[DIMENSION+1];

    struct tree *left, *right;
};

class KD{
    struct tree *root;
public:
    KD(){
        root = NULL;
    }
    void create_node(struct tree *&rt, int arr[]){
        rt = new tree();

        for(int i=0; i<DIMENSION; i++)
            rt->arr[i] = arr[i];

        rt->left = rt->right = NULL;
    }
    void input_fun();

    void insert_util(struct tree *&root, int arr[], int dd);
    void insertt(int a, int b);

    bool find_util(struct tree *root, int arr[], int dd);
    bool findd(int a, int b);

    void deletee(int a, int b);
    void delete_util(struct tree *&rt, int arr[], int dd);

    struct tree* min_successor(struct tree *rt, int fd, int dd);
    struct tree* min_node(struct tree *fi, struct tree *se, struct tree *thi, int dd);
    void point_copy(struct tree *f, struct tree *s);
};

struct tree* KD::min_node(struct tree *fi, struct tree *se, struct tree *thi, int dd)
{
    struct tree *tmp = fi;
    if(se != NULL && se->arr[dd] < tmp->arr[dd])
        tmp = se;
    if(thi != NULL && thi->arr[dd] < tmp->arr[dd])
        tmp = thi;
return tmp;
}

struct tree* KD::min_successor(struct tree *rt, int fd, int dd)
{
    if(rt == NULL)
        return NULL;

    dd = dd % DIMENSION;
    if(fd == dd)
    {
        if(rt->left == NULL)
            return rt;
        return min_successor(rt->left, fd, dd+1);
    }

    return min_node(rt, min_successor(rt->left, fd, dd+1), min_successor(rt->right, fd, dd+1), fd);
}

void KD::point_copy(struct tree *f, struct tree *s)
{
    for(int i=0; i<DIMENSION; i++)
        f->arr[i] = s->arr[i];
return;
}

void KD::delete_util(struct tree *&rt, int arr[], int dd)
{
    if(rt == NULL)
        return;
    dd = dd % DIMENSION;

    if(rt->arr[dd] == arr[dd])
    {
        bool f = true;
        for(int i=0; i<DIMENSION; i++)
        {
            if(rt->arr[i] == arr[i])
                continue;
            f = false;
            break;
        }
        if(f)
        {
            if(rt->right != NULL)
            {
                struct tree *tp = min_successor(rt->right, dd, dd+1);
                //cout << tp->arr[0]<< " " << tp->arr[1] << endl;
                point_copy(rt, tp);
                delete_util(rt->right, tp->arr, dd+1);
            }
            else if(rt->left != NULL)
            {
                struct tree *tp = min_successor(rt->left, dd, dd+1);
             //   cout << tp->arr[0]<< " " << tp->arr[1] << endl;
                point_copy(rt, tp);
                delete_util(rt->left, tp->arr, dd+1);
            }
            else{
                delete(rt);
                rt = NULL;
            }
        return;
        }
    }

    if(rt->arr[dd] < arr[dd])
        delete_util(rt->right, arr, dd+1);
    else
        delete_util(rt->left, arr, dd+1);
return;
}

void KD::deletee(int a, int b)
{
    int aa[] = {a, b};
    delete_util(root, aa, 0);
return;
}

bool KD::find_util(struct tree *root, int arr[], int dd)
{
    if(root == NULL)
        return false;
    dd = dd % DIMENSION;

    if(root->arr[dd] == arr[dd])
    {
        bool fl = true;
        for(int i=0; i<DIMENSION; i++)
        {
            if(root->arr[i] == arr[i])
                continue;
            fl = false;
            break;
        }
        if(fl)
            return fl;
    }

    if(root->arr[dd] < arr[dd])
        return find_util(root->right, arr, dd+1);
    else
        return find_util(root->left, arr, dd+1);
}

bool KD::findd(int a, int b)
{
    int aa[] = {a, b};
    return find_util(root, aa, 0);
};

void KD::insert_util(struct tree *&root, int arr[], int dd)
{
    if(root == NULL)
    {
        create_node(root, arr);
        return;
    }

    dd = dd % DIMENSION;

   // cout<< root->arr[dd] << " test " << arr[dd] <<endl;
    if(root->arr[dd] < arr[dd])
        insert_util(root->right, arr, dd+1);
    else
        insert_util(root->left, arr, dd+1);
}

void KD::insertt(int a, int b)
{
    int arr[] = {a, b};
    insert_util(root, arr, 0);
return;
}

void traverse(struct tree *rt)
{
    if(rt == NULL)
        return;
    cout<< rt->arr[0] << " " << rt->arr[1] << endl;

    traverse(rt->left);
    traverse(rt->right);
return;
}
void traverse2(struct tree *rt)
{
    if(rt == NULL)
        return;

    traverse2(rt->left);

    cout<< rt->arr[0] << " " << rt->arr[1] << endl;

    traverse2(rt->right);
return;
}

void traverse3(struct tree *rt)
{
    if(rt == NULL)
        return;

    traverse3(rt->left);
    traverse3(rt->right);
    cout<< rt->arr[0] << " " << rt->arr[1] << endl;
return;
}

void KD::input_fun()
{
    int point[][2] = {{3, 6}, {17, 15}, {13, 15}, {6, 12}, {9, 1}, {2, 7}, {10, 19}};

    for(int i=0; i<7; i++)
        insertt(point[i][0], point[i][1]);

    traverse(root);
    cout << endl;
//    traverse2(root);
//    cout << endl;
//    traverse3(root);

    if(findd(17, 15))
        cout<< "Found" << endl;
    else
        cout << "Not Found" << endl;

    deletee(10, 19);

    traverse(root);
return;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   KD kd;
   kd.input_fun();
return 0;
}
