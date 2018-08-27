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
int ind_tree[MAX_VAL];

class BIT{
    vector<vector<int> > graph;
    bitset<MAX_VAL> visited;
public:
    void initializ(){
        for(int i=0; i<MAX_VAL; i++)
            ind_tree[i] = 0;
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
    void construct_BIT(int *given_arra, int siz);

    /*
        Time Complexity : O(log n)
    */
    void update_BIT(int *given_arra, int pos, int val, int siz);

    /*
        Time Complexity : O(log n)
    */
    int sum_quary_in_BIT(int quary);
    int range_sum_quary_in_BIT(int qs, int qe);
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

void BIT::construct_BIT(int *given_arra, int siz)
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

void BIT::update_BIT(int *given_arra, int pos, int val, int siz)
{
    int t = pos + 1;
    int diff = val - given_arra[pos];
    given_arra[pos] = val;

    while(t <= siz){
        ind_tree[t] += diff;

        t = get_next(t);
    }
return;
}

int BIT::sum_quary_in_BIT(int quary_ind)
{
    int ans = 0;
    int t = quary_ind + 1;

    while(t > 0){
        ans += ind_tree[t];

        t = get_parent(t);
    }

    return ans;
}

int BIT::range_sum_quary_in_BIT(int qs, int qe)
{
    return sum_quary_in_BIT(qe) - sum_quary_in_BIT( qs-1 );
}

void BIT::input_fun()
{
    int arra[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};

    int siz = sizeof(arra)/sizeof(arra[0]);

    construct_BIT(arra, siz);

    cout<<range_sum_quary_in_BIT(3, 5)<<endl;

    update_BIT(arra, 3, 9, siz);

    cout<<range_sum_quary_in_BIT(3, 5)<<endl;

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
