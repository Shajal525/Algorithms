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

class BIT{
    vector<vector<int> > graph;
    bitset<MAX_VAL> visited;
public:
    void initializ(int *ind_tree_1, int *ind_tree_2){
        for(int i=0; i<MAX_VAL; i++)
            ind_tree_1[i] = ind_tree_2[i] = 0;
    }
    void input_fun();

    int get_parent(int n);  // Returns parent

    int get_next(int n);    // Return next index

    /*
        Time complexity : O(n log n)
        It takes n log n time.

        Space complexity : O(n)
        It takes N space.
    */
    void construct_BIT(int *ind_tree, int *given_arra, int siz);

    /*
        Time Complexity : O(log n)
    */
    void update_BIT(int *ind_tree, int pos, int val, int siz);

    /*
        Time Complexity : O(log n)

        Reference : katikkukreja.wardpress.com
    */
    void range_update(int *ind_tree1, int *ind_tree2, int qs, int qe, int val, int siz);
    /*
        Time Complexity : O(log n)
    */
    int sum_quary_in_BIT(int *ind_tree, int quary);
    int range_sum_quary_in_BIT(int *ind_tree1, int *ind_tree2, int qs, int qe);
    int range_sum(int *ind_tree1, int *ind_tree2, int q);
};

int BIT::get_parent(int n)
{
    // 2's complement
    int t = n;
    t = ~t;     // inverse
    t += 1;     // Add one

    t = t & n;  // And with original number

    return n - t;   // Subtract from original number
}

int BIT::get_next(int n)
{
    // 2's complement
    int t = n;
    t = ~t;     // inverse
    t += 1;     // Add one

    t = t & n;  // And with original number

    return n + t;   // Subtract from original number
}

void BIT::construct_BIT(int *ind_tree, int *given_arra, int siz)
{
    for(int i=0; i<siz; i++){
        int val = given_arra[i];
        int t = i + 1;

        while(t <= siz){
            ind_tree[t] += val;

            t = get_next(t);
        }
    }
return;
}

void BIT::update_BIT(int *ind_tree, int pos, int val, int siz)
{
    int t = pos + 1;

    while(t <= siz){
        ind_tree[t] += val;

        t = get_next(t);        // It's get_next
    }
return;
}

void BIT::range_update(int *ind_tree1, int *ind_tree2, int qs, int qe, int val, int siz)
{
    update_BIT(ind_tree1, qs, val, siz);
    update_BIT(ind_tree1, qe+1, -val, siz);

    update_BIT(ind_tree2, qs, val*(qs-1), siz);
    update_BIT(ind_tree2, qe+1, -val*(qe), siz);
return;
}

int BIT::sum_quary_in_BIT(int *ind_tree, int quary_ind)
{
    int ans = 0;
    int t = quary_ind + 1;

    while(t > 0){
        ans += ind_tree[t];

        t = get_parent(t);
    }

    return ans;
}

int BIT::range_sum(int *ind_tree1, int *ind_tree2, int q)
{
    return (sum_quary_in_BIT(ind_tree1, q) * q) - sum_quary_in_BIT(ind_tree2, q);
}

int BIT::range_sum_quary_in_BIT(int *ind_tree1, int *ind_tree2, int qs, int qe)
{
    return range_sum(ind_tree1, ind_tree2, qe) - range_sum(ind_tree1, ind_tree2, qs-1);
}

void BIT::input_fun()
{
    int ind_tree_1[MAX_VAL],ind_tree_2[MAX_VAL];
    initializ(ind_tree_1, ind_tree_2);
    int siz = 5,ann = 0;

    range_update(ind_tree_1, ind_tree_2, 0, 4, 5, 5);


    range_update(ind_tree_1, ind_tree_2, 2, 4, 10, 5);

    ann = range_sum_quary_in_BIT(ind_tree_1, ind_tree_2, 1, 4);

    cout<<ann<<endl;

   // cout<<get_parent(4)<<endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    BIT bc;
    bc.input_fun();
return 0;
}


