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

class MAX_FLOW{
    const static int V = 1000;
    int par[V];
    int min_res_flow[MAX_VAL];
public:

    /*
        This is called Ford-Fulkerson algorithm. We use BFS in this algorithm. So this is now Edmonds-Karp algorithm.
        We find path using BFS. If path exists then we minus minimum pipe capacity from each edge in that path and
        add minimum to the max flow.

        For directed flow graph[x][y] is flow from x to y and it's reverse graph[y][x] is zero. For bi-directional graph
        graph[x][y] = graph[y][x] = given flow. Every graph[x][y] is initialize to zero.

        If there is more then one source and sink then we take a super sink and source and connect all source and sink to that
        super source and sink and initialize those edge capacity to infinity.

        Maximum bipartite matching can be solved using max_flow. All applicants are connected with a source and all jobs are connected
        with sink and weight of each edge is 1. Here Time complexity is O(V * E).
        Hopcroft-Karp algorithm solve it in O(sqrt(V * E)).
    */
    int max_flow(int graph[][V], int source, int sink, int n);
    bool BFS(int graph[][V], int source, int sink, int n);

    /*
        For minimum cut we have to call same max flow function then again using same BFS in residual graph find reachable nodes.
        Then every edge from reachable node to non reachable node is min cut if there was connected in main graph.
    */
    void s_d_minimum_cut(int graph[][V], vector<pair<int,int> > result_edge, int source, int sink, int n);
};

bool MAX_FLOW::BFS(int graph[][V], int source, int sink, int n)
{
    queue<int> qu;
    qu.push(source);
    par[source] = source;
    min_res_flow[source] = INT_MAX;

    while(!qu.empty()){
        int u = qu.front();
        qu.pop();

        for(int i=1; i<=n; i++){
            if(par[i] == -1 && graph[u][i] > 0){
                qu.push(i);
                par[i] = u;
                min_res_flow[i] = min(min_res_flow[u], graph[u][i]);
                if(i == sink)
                    return true;
            }
        }
    }
return false;
}
int MAX_FLOW::max_flow(int graph[][V], int source, int sink, int n)    // For directed flow graph[x][y] is flow from x to y and
{                                                               // graph[x][y] is zero. For undirected graph
    int inf = INT_MAX;                                          // graph[x][y] = graph[y][x] = given flow.
    int max_flow_found = 0;                                     // Every graph[x][y] is initialize to zero.

    memset(par, -1, sizeof(par));
    while(BFS(graph, source, sink, n)){

        int x = sink;
        while(x != source){
            graph[par[x]][x] -= min_res_flow[sink];
            graph[x][par[x]] += min_res_flow[sink];
            x = par[x];
        }

        max_flow_found += min_res_flow[sink];

        memset(par, -1, sizeof(par));
    }
return max_flow_found;
}

void MAX_FLOW::s_d_minimum_cut(int graph[][V], vector<pair<int,int> > result_edge, int source, int sink, int n)
{
    int residual_graph[V][V];                  // Copy main graph to residual_graph
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            residual_graph[i][j] = graph[i][j];
        }
    }

    max_flow(residual_graph, source, sink, n);

    memset(par, -1, sizeof(par));

    BFS(residual_graph, source, sink, n);      // One more time call BFS. We can skip it as in max flow while loop we already
                                            // called it last time and it was false.
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(par[i] > 0 && par[j] == -1 && graph[i][j]){      // All the edge's from visited node to unvisited node is min cut edge.
                result_edge.push_back(make_pair(i,j));
            }
        }
    }
return;
}

int main()
{

return 0;
}
