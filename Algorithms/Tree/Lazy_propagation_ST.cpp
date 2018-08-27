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
#define INPUT freopen("C://Users/Shajal/Deskenddp/input.txt", "r+", stdin)
#define OUTPUT freopen("C://Users/Shajal/Deskenddp/out.txt", "r+", stdout)
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
#define inf INT_MAX
//int SET(int n,int i) {return (n|(1<<i));}
//int RESET(int n,int i) {return (n&~(1<<i));}
//bool check(int n,int i) {return (n&(1<<i));}
using namespace std;

//Template endds Here

int seg_tree[MAX_VAL];
int lazy[MAX_VAL];

// This is used when we have to update in a given range.
class LAZY_SEGMENT_TREE{
    bitset<MAX_VAL> visited;
public:
    void initializ(){
        for(int i=0; i<MAX_VAL; i++)
            lazy[i] = 0;
    }
    void input_fun();

    /*
        Time Complexity : O(n).
        Construction takes O(n) time.

        It takes the original array and size of original tree.

        We can also use segment tree for sum in given range.
    */
    void construct_LAZY_SEGMENT_TREE(int *given_arra, int siz); //This function remains unchanged for Lazy propagation
    void construct_LAZY_SEGMENT_TREE_util(int *given_arra, int start, int endd, int pos);

    /*
        Time Complexity : O(n).
        Query takes O(log n) time.

        It takes the original array, query start and end index, and size of original tree.
    */
    int range_min_quary(int *given_arra, int qu_st, int qu_en, int siz);    //Little change in Lazy propagation
    int range_min_quary_util(int start, int endd, int quary_start, int quary_endd, int pos);

    /*
        Time Complexity : O(n).
        Update takes O(log n) time.

        It takes the original array, position of node to be updated, new value and size of original tree.
    */
    void update_st(int *given_arra, int qs_pos, int qe_pos, int diff, int siz);
    void update_st_util(int start, int endd, int qs_pos, int qe_pos, int diff, int st_pos);
};

void LAZY_SEGMENT_TREE::construct_LAZY_SEGMENT_TREE_util(int *given_arra, int start, int endd, int pos)
{
    if(start == endd)
    {
        seg_tree[pos] = given_arra[endd];
        return;
    }

    int mid = start + ( (endd - start) / 2);

    construct_LAZY_SEGMENT_TREE_util(given_arra, start, mid, 2*pos+1);
    construct_LAZY_SEGMENT_TREE_util(given_arra, mid+1, endd, 2*pos+2);

    seg_tree[pos] = min(seg_tree[2*pos+1], seg_tree[2*pos+2]);
return;
}

void LAZY_SEGMENT_TREE::construct_LAZY_SEGMENT_TREE(int *given_arra, int siz)
{
    construct_LAZY_SEGMENT_TREE_util(given_arra, 0, siz-1, 0);
}


void LAZY_SEGMENT_TREE::update_st_util(int start, int endd, int qs_pos, int qe_pos, int diff, int st_pos)
{
    if(lazy[st_pos] != 0){                  // Calculate if lazy has value
        seg_tree[st_pos] += lazy[st_pos];   // If there is Sum query instead of RMQ then seg_tree[st_pos] += ( (endd - start +1) * lazy[st_pos] );

        if(start != endd){
            lazy[2*st_pos+1] += lazy[st_pos];
            lazy[2*st_pos+2] += lazy[st_pos];
        }

        lazy[st_pos] = 0;
    }

    if(qe_pos < start || qs_pos > endd) // No overlap
        return;

    if(start >= qs_pos && endd <= qe_pos){  // Total overlap
        seg_tree[st_pos] += diff;

        if(start != endd){
            lazy[2*st_pos+1] += diff;
            lazy[2*st_pos+2] += diff;
        }
        return;
    }

    int mid = (start + endd)/2;

    update_st_util(start, mid, qs_pos, qe_pos, diff, 2*st_pos+1);
    update_st_util(mid+1, endd, qs_pos, qe_pos, diff, 2*st_pos+2);

    seg_tree[st_pos] = min(seg_tree[2*st_pos+1], seg_tree[2*st_pos+2]);
return;
}
void LAZY_SEGMENT_TREE::update_st(int *given_arra, int qs_pos, int qe_pos, int diff, int siz)
{
    update_st_util(0, siz-1, qs_pos, qe_pos, diff, 0);
}


int LAZY_SEGMENT_TREE::range_min_quary_util(int start, int endd, int quary_start, int quary_endd, int st_pos)
{
    if(lazy[st_pos] != 0){                  // Calculate if lazy has value
        seg_tree[st_pos] += lazy[st_pos];   // If there is Sum query instead of RMQ then seg_tree[st_pos] += ( (endd - start +1) * lazy[st_pos] );

        if(start != endd){
            lazy[2*st_pos+1] += lazy[st_pos];
            lazy[2*st_pos+2] += lazy[st_pos];
        }

        lazy[st_pos] = 0;
    }

    // Now everything is same as for ST
    if(start >= quary_start && endd <= quary_endd)  // Total overlap
        return seg_tree[st_pos];

    if(start > quary_endd || endd < quary_start)    // No overlap
        return INT_MAX;

    int mid = (start + endd) / 2;

    return min(range_min_quary_util(start, mid, quary_start, quary_endd, 2*st_pos+1),
                               range_min_quary_util(mid+1, endd, quary_start, quary_endd, 2*st_pos+2));
}

int LAZY_SEGMENT_TREE::range_min_quary(int *given_arra, int qu_st, int qu_en, int siz)
{
    return  range_min_quary_util(0, siz-1, qu_st, qu_en, 0);
}

void LAZY_SEGMENT_TREE::input_fun()
{
    initializ();

    int arra[] = {1,3, 5, 7, 9, 11};
    int siz = sizeof(arra)/ sizeof(arra[0]);

    construct_LAZY_SEGMENT_TREE(arra, siz);

    cout<<range_min_quary(arra, 3, 5, siz)<<endl;

    update_st(arra, 1, 5, -5, siz);

    cout<<seg_tree[0]<<endl;

    cout<<range_min_quary(arra, 3, 4, siz)<<endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    LAZY_SEGMENT_TREE bc;
    bc.input_fun();
return 0;
}

