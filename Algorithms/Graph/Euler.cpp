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
//bool check(int n,int i) {return (n&(1<<i));}
using namespace std;

//My Template Ends Here

class EULER{
    const static int V = 100;
    vector<int> graph[V];
    bool vis[V];
public:

    /*
        This works for undirected graph.
        Requirement 1 for Euler Cycle or Path is :
             All nodes with non-zero degree are connected.
             We don't care about nodes with zero degree because they don't belong to
             Eulerian Cycle or Path (we only consider all edges)
        Requirement 2 for Euler Cycle:
            All nodes have even degree.
        Requirement 2 for Euler path:
            If zero or two nodes have odd degree and all other nodes have even degree.
            Note that only one vertex with odd degree is not possible in an
            undirected graph (sum of all degrees is always even in an undirected graph).
        Reference: http://www.geeksforgeeks.org/eulerian-path-and-circuit/
        Time complexity is O(N + E).
    */
    int euler_path_and_cycle_in_undirected_g();
    bool is_connected();
    void DFS(vector<int> graph[], int n);

    /*
        This works for directed graph.
        Requirement 1 for Euler Cycle:
             All nodes with nonzero degree belong to a single strongly connected component.
        Requirement 2 for Euler Cycle:
            In degree and out degree of every vertex is same.
        Reference: http://www.geeksforgeeks.org/euler-circuit-directed-graph/
        Time Complexity is O(V + E).
    */
    bool euler_cycle_in_directed(vector<int> reverse_graph[], int indegree[]);
    bool is_strongly_connected(vector<int> reverse_graph[]);

    /*

        Time complexity is O((V + E)^2).
        Hierholzer's Algorithm can do it in O(V + E). But it works in directed graph.
    */
    void print_Euler_tour_Fleuries_alg();
    void rmvEdge(int u, int v);
    void addEdge(int u, int v);
    int DFSCount(int u);
    void printEulerUtil(int u);
    bool isValidNextEdge(int u, int v);

    /*
        This works for directed graphs.
        Reference: http://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/
        Time complexity is O(V + E).
    */
    void printCircuit_Hierholzer(vector< vector<int> > graph);
    void My_print_util(int n);
};



void EULER::DFS(vector<int> graph[], int n)
{
    int siz = graph[n].size();
    vis[n] = true;

    for(int i=0; i<siz; i++){
        if(vis[graph[n][i]] == false)
            DFS(graph, graph[n][i]);
    }
return;
}

bool EULER::is_connected()
{
    int i=0;
    while(graph[i].size() == 0)     // If in-degree is zero then then we can skip that node. Because there is no edge.
        i++;

    if(i == V)          // If all nodes have zero in-degree then that is Euler graph.
        return true;

    for(int i=0; i<V; i++)  // Initially all nodes are unvisited.
        vis[i] = false;

    DFS(graph, i);         // Go through all the nodes.

    for(int i=0; i<V; i++){
        if(vis[i] == false && graph[i].size() > 0)  // If node is not visited and it has in-degree more then 0
            return false;                           // then the graph is not connected. Euler cycle or path is not possible.
    }
return true;
}

// This function return 0 if Euler path or cycle nothing is possible.
// It return 1 if Euler cycle exists in that graph.
// It return 2 if Euler path exists but no Euler cycle.
int EULER::euler_path_and_cycle_in_undirected_g()
{
    if(is_connected() == false)  // Check if the graph is connected.
        return 0;

    // If graph is connected and number of odd degree nodes is zero then there is a Euler Cycle.
    // If graph is connected and number of odd degree nodes is 2 then there is a Euler path.
    // There can't be 1 odd in-degree node because total sum of in-degree is always even
    int odd_deg_cou = 0;

    for(int i=0; i<V; i++){
        if(graph[i].size() & 1)
            odd_deg_cou++;
    }

    if(odd_deg_cou == 0){
        printf("Graph consists Euler Cycle.\n");
        return 1;
    }
    else if(odd_deg_cou == 2){
        printf("Graph consists Euler path.\n");
        return 2;
    }
    return 0;
}

bool EULER::is_strongly_connected(vector<int> reverse_graph[])
{
    for(int i=0; i<V; i++)
        vis[i] = false;

    int n=0;
    while(graph[n].size() == 0);    // Get first non-zero out-degree node.

    DFS(graph, n);

    for (int i = 0; i < V; i++)
        if (graph[i].size() > 0 && vis[i] == false)     // After DFS if any node with out-degree greater then zero not visited
              return false;                             // Then graph is not connected.

    for(int i=0; i<V; i++)
        vis[i] = false;

    DFS(reverse_graph, n);      // For reverse graph again perform DFS

    // If all nodes are not visited in second DFS, then return false
    for (int i = 0; i < V; i++)
        if (graph[i].size() > 0 && vis[i] == false)     // After second DFS if any node with in-degree greater then zero not visited
             return false;                              // Then graph is not strongly connected.

return true;
}

bool EULER::euler_cycle_in_directed(vector<int> reverse_graph[], int indegree[])
{
    if(is_strongly_connected(reverse_graph) == false)   // Check if the graph is Strongly Connected.
        return false;

     // Check if in degree and out degree of every vertex is same
    for (int i = 0; i < V; i++)
        if ((int)graph[i].size() != indegree[i])     // For any node if In degree out degree differs then Euler cycle not possible.
            return false;

return true;
}


void EULER::addEdge(int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
// This function removes edge u-v from graph.  It removes the edge by
// replacing adjcent vertex value with -1.
void EULER::rmvEdge(int u, int v)
{
    // Find v in adjacency list of u and replace it with -1
    vector<int>::iterator iv = find(graph[u].begin(), graph[u].end(), v);
    *iv = -1;

    // Find u in adjacency list of v and replace it with -1
    vector<int>::iterator iu = find(graph[v].begin(), graph[v].end(), u);
    *iu = -1;
}

// A DFS based function to count reachable vertices from v
int EULER::DFSCount(int v)
{
    // Mark the current node as visited
    vis[v] = true;
    int count = 1;

    // Recur for all vertices adjacent to this vertex
    vector<int>::iterator i;
    for (i = graph[v].begin(); i != graph[v].end(); ++i)
        if (*i != -1 && !vis[*i])
            count += DFSCount(*i);

    return count;
}
// The function to check if edge u-v can be considered as next edge in
// Euler Tout
bool EULER::isValidNextEdge(int u, int v)
{
    // The edge u-v is valid in one of the following two cases:

    // 1) If v is the only adjacent vertex of u
    int count = 0;  // To store count of adjacent vertices
    vector<int>::iterator i;
    for (i = graph[u].begin(); i != graph[u].end(); ++i)
        if (*i != -1)
            count++;
    if (count == 1)
        return true;

    // 2) If there are multiple adjacents, then u-v is not a bridge
    // Do following steps to check if u-v is a bridge

    // 2.a) count of vertices reachable from u
    bool vis[V];
    memset(vis, false, V);
    int count1 = DFSCount(u);

    // 2.b) Remove edge (u, v) and after removing the edge, count
    // vertices reachable from u
    rmvEdge(u, v);
    memset(vis, false, V);
    int count2 = DFSCount(u);

    // 2.c) Add the edge back to the graph
    addEdge(u, v);

    // 2.d) If count1 is greater, then edge (u, v) is a bridge
    return (count1 > count2)? false: true;
}
void EULER::printEulerUtil(int u)
{
    // Recur for all the vertices adjacent to this vertex
    vector<int>::iterator i;
    for (i = graph[u].begin(); i != graph[u].end(); ++i)
    {
        int v = *i;

        // If edge u-v is not removed and it's a a valid next edge
        if (v != -1 && isValidNextEdge(u, v))
        {
            cout << u << "-" << v << "  ";
            rmvEdge(u, v);
            printEulerUtil(v);
        }
    }
}

void EULER::print_Euler_tour_Fleuries_alg()
{
    // Find a vertex with odd degree
    int u = 0;
    for (int i = 0; i < V; i++)
        if (graph[i].size() & 1)
        {
            u = i;
            break;
        }

    // Print tour starting from odd out-degree node.
    printEulerUtil(u);
    cout << endl;
}

// This function only works if we declare 'graph' globaly
vector< vector<int> > graph2;
void EULER::My_print_util(int n)
{
    while(graph2[n].size() != 0){

        int next_n = graph2[n].back();
        graph2[n].pop_back();

        My_print_util(next_n);
    }

    printf("%d -> ", n);
}

void EULER::printCircuit_Hierholzer(vector< vector<int> > adj)
{
    // We can skip all below activities using this function.
    My_print_util(0);
    cout << endl;

    // adj represents the adjacency list of
    // the directed graph
    // edge_count represents the number of edges
    // emerging from a vertex
    int edge_count[V];

    for (int i=0; i<(int)adj.size(); i++)
    {
        //find the count of edges to keep track
        //of unused edges
        edge_count[i] = adj[i].size();
    }

    if (!adj.size())
        return; //empty graph

    // Maintain a stack to keep vertices
    stack<int> curr_path;

    // vector to store final circuit
    vector<int> circuit;

    // start from any vertex
    curr_path.push(0);
    int curr_v = 0; // Current vertex

    while (!curr_path.empty())
    {
        // If there's remaining edge
        if (edge_count[curr_v])
        {
            // Push the vertex
            curr_path.push(curr_v);

            // Find the next vertex using an edge
            int next_v = adj[curr_v].back();

            // and remove that edge
            edge_count[curr_v]--;
            adj[curr_v].pop_back();

            // Move to next vertex
            curr_v = next_v;
        }

        // back-track to find remaining circuit
        else
        {
            circuit.push_back(curr_v);

            // Back-tracking
            curr_v = curr_path.top();
            curr_path.pop();
        }
    }

    // we've got the circuit, now print it in reverse
    for (int i=circuit.size()-1; i>=0; i--)
    {
        cout << circuit[i];
        if (i)
           cout<<" -> ";
    }
    cout << endl;
}

int main()
{
    graph2 = {{1}, {2, 3}, {3}, {4, 5}, {5}, {0, 1}};

    EULER e;
    e.printCircuit_Hierholzer(graph2);
return 0;
}

