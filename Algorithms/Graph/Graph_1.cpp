// MY TEMPLATE  Starts here

/*
*********************************************
*                                           *
*    Name: S. M. Shaheduzzaman(Shajal)      *
*                                           *
*    Begum Rokeya Uniersity, Rangpur        *
*                                           *
*********************************************
*/
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
#define OUTPUT freopen("C://Users/Shajal/Desktop/out.txt", "r+", stdout)
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
#define MAX_VAL 3000
using namespace std;
//int SET(int n,int i) {return (n|(1<<i));}
//int RESET(int n,int i) {return (n&~(1<<i));}
//boolean check(int n,int i) {return (n&(1<<i));}

// MY TEMPLATE Ends here

struct graph_struct;

class GRAPH
{
    bool visited[MAX_VAL];
public:
    /*
        This is called level order traversal.
        Time complexity of BFS is batter then DFS.
        In this algorithm we visit nodes in a graph level by level using queue.
        Using this we can find shortest path in unweighted graph.
        This also works in 2D grid.
        It takes a graph, level array and source.
        The level array holds shortest path from source to all nodes.

        Time Complexity is O(V + E).
    */
    void BFS(vector<int> graph[], int level[], int source);

    /*
        In DFS we traverse a graph like BFS but here we don't traverse level by level.
        It reaches depth of a node then visit it.
        Here we use recursive function to traverse graph and find starting time and finishing time.
        Finishing time can be used to get topological order.
        Using color array we can detect cycle in graph in DFS function.
    */
    void DFS(vector<int> graph[], int spurce);

    /*
        Minimum spanning tree is subgraph of a graph which is a tree(there will be no cycle).
        This will be a tree which consists of all the nodes in such a way that total cost of the all the edges are minimum.
        Prim's algorithm works as : It takes a node then find the smallest edge and visit through that node.
        Then among all the visited node go through the smallest edge and continue this process until all nodes are visited.
        It takes graph array of pair. first one is weight of edge and second one is index of node.
        It returns total weight of MST
	Time Complexity: O(E log V).
    */
    int Minimum_Spanning_Tree_Prims(vector<pair<int,int> > graph[],int source);

    /*
        Minimum spanning tree is subgraph of a graph which is a tree(there will be no cycle).
        This will be a tree which consists of all the nodes in such a way that total cost of the all the edges are minimum.
        Kruskal's algorithm works as : It makes a structure of source node,destination node and  weight of that edge.
        Then in array(or vector) of that structure take input. Then sort the array according to weight in ascending order.
        Then using disjoint sets union function take to node and mark it as MST edge.
        It takes array of that structure.
        It returns total weight of MST
	Time Complexity: O(E log V).
    */
    int Minimum_Spanning_Tree_Kruskal(graph_struct g_st[], vector<int> result, int num_edge, int num_node);

    /*
        Same as MST just after sorting find MST then remove 1st edge again calculate MST,then remove 2nd edge again find MST.
        Continue that process and find minimum value among them.
    */
    int Second_best_MST(graph_struct g_st[], vector<int> result, int num_edge, int num_node);

    /*
        For topological sort's iterative version we have to calculate in-degree of each node while taking input.
        This is Kahn's algorithm.
        Time complexity O(V + E).
    */
    void Topological_Sort_Iterative(vector<int> graph[], int indegree[], queue<int> top_sorted_qu, int n);

    /*
        Dose same thing as iterative version but this version is much batter and easy to code.
        It just traverse full graph tree. There can't be cycle in topological graphs.
        It takes graph vector array, stack to save result and node number to determine we are working with which node.
        It save the top sorted nodes in the stack.
    */
    void Topological_Sort_Recursive(vector<int> graph[], stack<int> top_sorted_stack, int n);

};

void GRAPH::BFS(vector<int> graph[], int level[], int source)
{
    // My level array also doing the task of visited array.
    for(int i=0; i<MAX_VAL; i++)
        level[i] = -1;

    queue<int> qu;
    qu.push(source);

    level[source] = 0;

    while(!qu.empty()){

        int u = qu.front();
        qu.pop();

        int siz = graph[u].size();

        for(int i = 0; i<siz; i++){
            int v = graph[u][i];
            if(level[v] == -1){
                level[v] = level[u] + 1;
                qu.push(v);
            }
        }
    }
return;
}

#define WHITE 1         // Color array is initialized as WHITE
#define GRAY 2
#define BLACK 3
static int timeee = 0;
int color[100],discovery_time[100],finishing_time[100];
void GRAPH::DFS(vector<int> graph[], int source)
{
    timeee++;
    discovery_time[source] = timeee;     // Using finishing time we can easily calculate topological order

    color[source] = GRAY;               // Colors are used to find cycle in graph. In undirected graph we can find
                                        // cycle without color. Then we have to use visited array and track parent of each node.
    int siz = graph[source].size();     // If visited node again found and that is not parent of source then that is cycle.

    for(int i=0; i<siz; i++){
        int v = graph[source][i];

        if(color[v] == WHITE){
            DFS(graph, v);
        }
        if(color[v] == GRAY){
            // Cycle found
        }
    }
    timeee++;
    finishing_time[source] = timeee;
    color[source] = BLACK;
return;
}

struct stru{
    int index;
    int cost;

    bool operator<(const stru &a)const{
        return a.cost < cost;

        // For floating point cost.
        //return (cost - a.cost) > 1e-9;
    }
    stru(int a, int b) : index(a), cost(b){}
    stru(){};
};
int GRAPH::Minimum_Spanning_Tree_Prims(vector<pair<int,int> > graph[],int source)
{
    stru st;

    int total_weight_of_MST = 0;

    int visited[MAX_VAL];
    memset(visited, -1, sizeof(visited));

    //visited[source] = 1;

    priority_queue<stru> pq;             //This is used to find minimum edge among all

    pq.push(stru(source, 0));
    int siz = graph[source].size();

    while(!pq.empty()){
        stru ss = pq.top();
        pq.pop();

        if(visited[ss.index] == -1){
            visited[ss.index] = 1;

            total_weight_of_MST += ss.cost;

            siz = graph[ss.index].size();

            for(int i=0; i<siz; i++){
                st.index = graph[ss.index][i].first;
                st.cost = graph[ss.index][i].second;
                pq.push(st);
            }

        }
    }
return total_weight_of_MST;
}

struct graph_struct{
    int s,d,w;

    bool operator<(const graph_struct ss)const {
        return w<ss.w;
    }
};
int parent[100005];
int union_find(int n)
{
    if(parent[n] == -1)
        return n;
    return parent[n] = union_find(parent[n]);
}
int GRAPH::Minimum_Spanning_Tree_Kruskal(graph_struct g_st[], vector<int> result, int num_edge, int num_node)
{
    int total_weight = 0;
    int edge_cou = 0;

    sort(g_st, g_st+num_edge);
    memset(parent, -1, sizeof(parent));

    for(int i=0; i<num_edge; i++){
        int u = union_find(g_st[i].s);
        int v = union_find(g_st[i].d);

        if(u != v){
            parent[u] = v;

            result.push_back(i);
            edge_cou++;

            total_weight += g_st[i].w;
            if(edge_cou == num_node - 1){
                break;
            }

        }
    }
return (edge_cou == num_node - 1) ? total_weight : -1;
}

int GRAPH::Second_best_MST(graph_struct g_st[], vector<int> result, int num_edge, int num_node)
{
    // See UVa_10462 (solved) using prims algorithm.
    int second_best = INT_MAX;
    // Same as Kruskal's MST. If we call same function we have to take result array. We need that array
    Minimum_Spanning_Tree_Kruskal(g_st, result, num_edge,num_node);

    // Then for every edge in result array we will erase one edge each time and calculate MST and save the minimum one.
    for(int i=0; i<result.size(); i++){
       // Now we pass result[i] index int MST function and block that edge and calculate MST.
       // We do this every time and save minimum.
       // But in this MST function we don't have to sort and save result
    }
return second_best;
}


void GRAPH::Topological_Sort_Iterative(vector<int> graph[], int indegree[], queue<int> top_sorted_qu, int n)
{
    // This is Kahn's algorithm. Time complexity O(V + E).
    queue<int> qu;  // For storing all nodes with in-degree zero.
   // vector<int> result;

    for(int i=1; i<=n; i++)
        if(indegree[i] == 0)
            qu.push(i);

    while(!qu.empty()){
        int u = qu.front();
        qu.pop();

        // result.push_back(u);
        cout<<u<<" ";

        int siz = graph[u].size();

        for(int i=0; i<siz; i++){
            int v = graph[u][i];

            if(--indegree[v] == 0)  // If adjacent in-degree become zero then push in the queue.
                qu.push(v);
        }
    }

//    int siz = result.size();
//    for(int i=0; i<siz; i++)
//        cout<<result[i]<<" ";
    cout<<endl;
return;
}

void GRAPH::Topological_Sort_Recursive(vector<int> graph[], stack<int> top_sorted_stack, int n)
{
    int siz = graph[n].size();
    visited[n] = true;

    for(int i=0; i<siz; i++){
        if(!visited[graph[n][i]])
            Topological_Sort_Recursive(graph, top_sorted_stack, graph[n][i]);
    }

    top_sorted_stack.push(n);
return;
}

int main()
{

}

