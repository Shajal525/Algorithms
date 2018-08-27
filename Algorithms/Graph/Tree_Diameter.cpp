//My Template Starts Here

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
#define ll long long
#define ui unsigned int
#define MP make_pair
#define INPUT freopen("C://Users/Shajal/Desktop/input.txt", "r+", stdin)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define sc scanf
#define pf printf
#define out std::cout
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
//bool cheaq(int n,int i) {return (n&(1<<i));}
using namespace std;

//My Template Ends Here

class TREE_DIAMETER{
    struct stru{
        int level,node;
    };

    int level[1000];
public:

    /*
        This algorithm only perform 2 BFS and find tree diameter.
        This algorithm only works for tree's. Not work in other graphs.
        In other graph finding diameter is a version of finding longest path and that is N-P hard problem.
        Time Complexity is O(V + K). Same as BFS.
    */
    int tree_diameter(vector<int> graph[], int source);
    stru BFS(vector<int> graph[], int source);
};


TREE_DIAMETER::stru TREE_DIAMETER::BFS(vector<int> graph[], int source)
{
    queue<int> qu;
    qu.push(source);
    stru st;
    st.level = st.node = 0;

    while(!qu.empty()){
        int s = qu.front();
        qu.pop();

        int siz = graph[s].size();

        for(int i=0; i<siz; i++){
            int d = graph[s][i];
            if(level[d] == -1){
                qu.push(d);
                level[d] = level[s] + 1;

                if(level[d] > st.level){
                    st.level = level[d];
                    st.node = d;
                }
            }
        }
    }
return st;
}

int TREE_DIAMETER::tree_diameter(vector<int> graph[], int source)
{
    memset(level, -1, sizeof(level));
    stru st = BFS(graph, 0);                // Start BFS from any node and find farthest node

    memset(level, -1, sizeof(level));
    st = BFS(graph, st.node);               // Now call BFS from previous found farthest node. this time BFS return tree diameter.

return st.level;
}

int main()
{

return 0;
}
