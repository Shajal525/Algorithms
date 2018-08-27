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
#define ALPHABET 26

struct tree{
    struct tree *chiel[ALPHABET];
    bool is_leaf;
};

class TRIE{
    struct tree *root;
public:
    TRIE(){
        root = create_node();
    }
    struct tree* create_node()
    {
        struct tree* st = new tree();
        for(int i=0; i<ALPHABET; i++)
            st->chiel[i] = NULL;
        st->is_leaf = false;
        return st;
    }
    void input_fun();
    void insertt(struct tree *rt, string st);
    bool searchh(struct tree *rt, string st);
    bool deletee(string st);
    bool delete_helper(struct tree *rt, int level, int len);
    bool is_it_free(struct tree *rt);
};

bool TRIE::is_it_free(struct tree *rt)
{
    for(int i=0; i<ALPHABET; i++)
        if(rt->chiel[i] != NULL)
            return false;
return true;
}

bool TRIE::delete_helper(struct tree *rt, int level, int len)
{
    if(rt == NULL)
        return false;
    if(level == len){
        if(rt->is_leaf){
            rt->is_leaf = false;

            if(is_it_free(rt))
                return true;
        }
        return false;
    }
    else{

    }
}

bool TRIE::deletee(string st)
{
    return delete_helper(root, 0, st.length());
}

bool TRIE::searchh(struct tree *rt, string st)
{
    int le = st.length();
    int n;

    for(int i=0; i<le; i++){
        n = st[i] - 'a';
        if(rt->chiel[n] == NULL)
            return false;

        rt = rt->chiel[n];
    }
    if(rt!= NULL && rt->is_leaf)
        return true;
return false;
}

void TRIE::insertt(struct tree *rt, string st)
{
    int le = st.length();
    int n;

    for(int i=0; i<le; i++){
        n = st[i] - 'a';
        if(rt->chiel[n] == NULL)
            rt->chiel[n] = create_node();

        rt = rt->chiel[n];
    }

    rt->is_leaf = true;
}

void TRIE::input_fun()
{
    insertt(root, "shajal");
    insertt(root, "shajalil");
    insertt(root, "shushmoy");
    insertt(root, "shutup");

    cout << searchh(root, "shajal") << endl;
    cout << searchh(root, "shajali") << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    TRIE bc;
    bc.input_fun();
return 0;
}
