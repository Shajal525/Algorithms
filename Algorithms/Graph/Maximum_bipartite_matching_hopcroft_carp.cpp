//My Template Starts Here

/*******************************************\
*                                           *
*  # Name: S. M. Shaheduzzaman(Shajal)      *
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

const int INF = 100000;
const int NIL = 0;
const int L = 10;     // Number of nodes on left. Numbered from 1 to N.
const int R = 10;     // Number of nodes on right. Numbered from N+1 to N+M.

class MBM_Hopcroft_karp{
    int edge_from_L_node_to_R[L];
    int edge_from_R_node_to_L[R];
    int dis[L + R + 2];
    vector<int> graph[L];    // Input graph
public:

    /*
        For maximum bipartite matching we can use MAX FLOW algorithm but its complexity is O(V * E).
        Reference : http://www.geeksforgeeks.org/hopcroft-karp-algorithm-for-maximum-matching-set-1-introduction
        Complexity of this algorithm is O(sqrt(V * E)).
    */
    bool BFS();
    bool DFS(int u);
    int hopcroft();
};


bool MBM_Hopcroft_karp::BFS()
{
    queue<int> qu;          // Store all free nodes on left in this queue.

    for(int i=1; i<=L; i++){
        if(edge_from_L_node_to_R[i] == NIL){
            dis[i] = 0;             // If node is free distance is zero.
            qu.push(i);
        }
        else dis[i] = INF;          // Else distance is infinity.
    }
    dis[NIL] = INF;                 // Distance of NIL is also infinity.

    while(!qu.empty()){
        int u = qu.front();
        qu.pop();

        if(u != NIL){
            int siz = graph[u].size();

            for(int i=0; i<siz; i++){
                int v = graph[u][i];

                if(dis[edge_from_R_node_to_L[v]] == INF){    // Matching is previously matched edges from v. v is in right side so match of v must
                    // be on left. Distance must be INF in first query. Because match can be either NIL or a matched node on left for
                    // which we initialized dis as INF. If matched is NIL that means that v is still free. Then that is augmented path.
                    dis[edge_from_R_node_to_L[v]] = dis[u] + 1;      // Change distance from infinity to previous level plus 1.
                    qu.push(edge_from_R_node_to_L[i]);
                }
            }
        }
    }
return dis[NIL] != INF;     // If NIL found or augmented path found than distance must be changed from INF to something.
}

bool MBM_Hopcroft_karp::DFS(int u)
{
    if(u == NIL)            // If u is NIL that is a path
        return true;

    int siz = graph[u].size();
    for(int i=0; i<siz; i++){
        int v = graph[u][i];

        if(dis[edge_from_R_node_to_L[v]] == dis[u] + 1){     // If this condition holds that means it may be a path in augmented path.
            if(DFS(edge_from_R_node_to_L[v])){       // Continue searching for NIL node.
                edge_from_L_node_to_R[u] = v;        // If NIL found then make new relations.
                edge_from_R_node_to_L[v] = u;
                return true;
            }
        }
    }
    dis[u] = INF;

return false;
}

int MBM_Hopcroft_karp::hopcroft()
{
    int result = 0;
    memset(edge_from_L_node_to_R, NIL, sizeof(edge_from_L_node_to_R));        // Initially All nodes are edged with NIL
    memset(edge_from_R_node_to_L, NIL, sizeof(edge_from_R_node_to_L));

    while(BFS()){                   // BFS find augmented path. If found return true.

        for(int i=1; i<=L; i++){        // For each node on left
            if(edge_from_L_node_to_R[i] == NIL && DFS(i))    // check is that node still free and is augmented path is from this node
                result++;                       // if so then maximum bipartite matching increase.
        }
    }
return result;
}

int main()
{

return 0;
}
