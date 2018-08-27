// MY TEMPLATE  Starts here


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
using namespace std;
//int SET(int n,int i) {return (n|(1<<i));}
//int RESET(int n,int i) {return (n&~(1<<i));}
//boolean check(int n,int i) {return (n&(1<<i));}

// MY TEMPLATE Ends here

struct stru;
class SHORTEST_PATH{
public:
    /*
        Dijkstra is almost same as BFS. Here we have need 1 extra edge_cos array to save cost from source to destination.
        In a Lowest_cost array we will save shortest path. First we initialize Lowest_cost array to infinity.
        Then in for loop we update Lowest_cost array if already the cost is bigger.
        Graph is same as BFS graph array. Edge cost is a two dimensional array that indicates cost from going u to v.
        If we use normal queue then same node will be visited twice or more. If we use priority queue then this problem reduces.
        This will not work if negative edge is present at the graph.
        Time Complexity is O(N.logN + E);
    */
    void dijkstra(vector<int> graph[], int edge_cost[][1000], int Lowest_cost[], int source);

    /*
        In this algorithm we have to take a mid node k and try to establish a connection from s to d using that node.
        Repeat that process for each k then we are done.
        We can print the path using print_path function. In next array we save which is mid between s and d.
        Using this algorithm we can get all pair shortest path. That means shortest path from any source node to any destination node.
        This will not work if negative edge is present at the graph.
        Time complexity is O(N^3).
    */
    void flowed_warshal(int adjacency_matrix[][1000], int max_node);

    /*
        In this algorithm we have to use relax technique used inside Dijkstra for loop for each node.
        We have to do it number of node minus 1 time to get shortest path from source to any node.
        After those part we will try to relax all edges one more time. If this time any relaxation function worked
        then we can say there is negative cycle in that graph.
        This is only shortest path algorithm that works for negative edge.
        This algorithm can also detect negative cycle in graph.
        It can also find shortest path using exactly k number of edges.
        Time complexity is O(N * E).
    */
    void ballman_ford(vector<stru> edges, int lowest_cost[], int source, int num_node);

    // We can also calculate some shortest path using MATRIX Exponentiation.
    /*
        This algorithm finds shortest path using k edges.
        This is naive approach.
        Time complexity is O( V^k ).
    */
    int shortest_path_using_k_edges(int graph[][1000], int u, int v, int k);

    /*
        This algorithm also finds shortest path using k edges.
        This is dynamic approach.
        Time complexity is O( (V^3) * K ).
        Batter then naive approach.
        Space complexity is O( (V^2) * K ).
    */
    int shortest_path_using_k_edges_dynamic(int graph[][1000], int u, int v, int k);
};

// Second best Shortest Path using Dijkstra. Ex. Light_OJ_1099(solved).
// Using specific roads but not more them D of those roads. Ex. Light_OJ_1281(Solved).
void SHORTEST_PATH::dijkstra(vector<int> graph[], int edge_cost[][1000], int Lowest_cost[], int source)
{
    memset(Lowest_cost, INT_MAX, sizeof(Lowest_cost));   // My level array also doing the task of visited array.

    priority_queue<int> pq;	// I think this is wrong. This will sort in descending order
    // Should use this. This will sort in ascending order of weight. Here Pair.first is weight and pair.second is index v.
//    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push(source);

    Lowest_cost[source] = 0;

    while(!pq.empty()){

        int u = pq.top();
        pq.pop();

        int siz = graph[u].size();          // Here graph array is edge's and lowest_cost is cost from u to v edge.

        for(int i = 0; i<siz; i++){
            int v = graph[u][i];
            if(Lowest_cost[u] + edge_cost[u][v] < Lowest_cost[v]){
                Lowest_cost[v] = Lowest_cost[u] + edge_cost[u][v];
                pq.push(v);
            }
        }
    }
return;
}


void print_path(int next[][1000], int s, int d)
{
    vector<int> path;
    path.push_back(s);

    while(s != d){              // if (s != d) then there is a mid node which is saved at next[s][d].
        s = next[s][d];
        path.push_back(s);
    }

    int siz = path.size();

    for(int i=0; i<siz; i++){
        printf("%d ", path[i]);
    }

return;
}
void SHORTEST_PATH::flowed_warshal(int adjacency_matrix[][1000], int max_node)
{
    int next[1000][1000];
    for(int i=0; i<max_node; i++){
        for(int j=0; j<max_node; j++){
            next[i][j] = j;
        }
    }

    for(int k=0; k<=max_node; k++){
        for(int i=0; i<=max_node; i++){
            for(int j=0; j<=max_node; j++){
                if(adjacency_matrix[i][j] > adjacency_matrix[i][k] + adjacency_matrix[k][j]){
                    adjacency_matrix[i][j] = adjacency_matrix[i][k] + adjacency_matrix[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    print_path(next, 0, 5);

return;
}

struct stru{
    int u,v,cost;
};
void SHORTEST_PATH::ballman_ford(vector<stru> edges, int lowest_cost[], int source, int num_node)
{
    int inf = INT_MAX;
    for(int i=0; i<=num_node; i++){
        lowest_cost[i] = inf;
    }
    lowest_cost[source] = 0;

    int siz = edges.size();
    for(int i=1; i<num_node; i++){        // We have to relax each edge num_node-1 time
        for(int j=0; j<siz; j++){
            int u = edges[j].u;
            int v = edges[j].v;
            int c = edges[j].cost;

            if(lowest_cost[u] != inf && lowest_cost[u] + c < lowest_cost[v])
                lowest_cost[v] = lowest_cost[u] + c;
        }
    }

    for(int j=0; j<siz; j++){
        int u = edges[j].u;
        int v = edges[j].v;
        int c = edges[j].cost;
        if(lowest_cost[u] != inf && lowest_cost[u] + c < lowest_cost[v]){
            printf("Negative edge found!!!\\n");
        }
    }
return;
}

// We can find shortest path using k edges using Bellman-Ford.
// Ex. UVa_11280(solved).
int SHORTEST_PATH::shortest_path_using_k_edges(int graph[][1000], int u, int v, int k)
{
    if(k == 0 && u == v)
        return 0;
    if(k <= 0) return INT_MAX;

    int res = INT_MAX;
    for(int i=0; i<1000; i++){
        if(graph[u][i] != INT_MAX && i!=u && i!=v){
            int recur = shortest_path_using_k_edges(graph, i, v, k-1);
            if(recur != INT_MAX)
                res = min(res, graph[u][i] + recur);
        }
    }
return res;
}

int SHORTEST_PATH::shortest_path_using_k_edges_dynamic(int graph[][1000], int u, int v, int k)
{
    int inf = INT_MAX;
    int V = 1000;
    int srt_pt[V][V][k+1];

    for(int e=0; e<=k; e++){

        for(int i=0; i<V; i++){

            for(int j=0; j<V; j++){

                srt_pt[i][j][e] = inf;

                if(e == 0 && i==j)
                    srt_pt[i][j][e] = 0;

                else if(e == 1)
                    srt_pt[i][j][e] = graph[i][j];

                else if(e>1){

                    for(int a=0; a<V; a++){
                        if(graph[i][a] != inf && a != j && a != i && srt_pt[a][j][e-1] != inf){
                            srt_pt[i][j][e] = min(srt_pt[i][j][e], graph[i][a] + srt_pt[a][j][e-1]);
                        }
                    }

                }
            }
        }
    }
return srt_pt[u][v][k];
}

int main()
{

}
