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
struct node_deg_pair;

class GRAPH_COLORING{
    const static int V = 1000;  // Max number of nodes
    const static int m = 10;     // Color's
    int graph[V][V];    // Adjacency Matrix of graph
    int colors[V];      // Color of each node's
public:

    /*
        This function return approximate minimum color needed to color a graph.
        This is called Welsh-Powell algorithm.
        This algorithm sort all nodes according to there in-degree.
        Time complexity is O(N^2 + E).
    */
    int min_color(node_deg_pair nd[], vector<int> graph[], int num_of_node);

    /*
        This is the algorithm to check if a graph can be colored with M number of colors.
        I think Time Complexity is O(N^2 * Colors).
        I think we can calculate minimum number of color needed to color a graph. Then we have to check
        color_graph_with_m_color() function 1 to M time until that function return true.
    */
    void color_graph_with_m_color(int number_of_nodes, int number_of_colors, int n);
    bool graph_color_util(int number_of_nodes, int number_of_colors, int n);
    bool is_safe(int number_of_nodes, int color, int node);

    /*
        We can check if a graph bipartite or not. If a graph can be colored using two color then graph is bipartite.
        We can check this using two BFS function.
    */
};


struct node_deg_pair{
    int n,deg;

    bool operator<(const node_deg_pair nn)const{
        return deg<nn.deg;     // Sign not confirmed
    }
};
int GRAPH_COLORING::min_color(node_deg_pair nd[], vector<int> graph[], int num_of_node)
{
    int available[num_of_node];     // Available colors.
    int color[num_of_node];         // color of a node.
    sort(nd, nd+num_of_node);       // Sort nodes according to in-degree.
    int max_color_used = 0;

    for(int i=0; i<=num_of_node; i++)   // Initially all nodes are free.
        color[i] = -1;

    for(int i=1; i<=num_of_node; i++){      // For all node
        int n = nd[i].n;

        for(int j=1; j<=num_of_node; j++)   // Initially all colors are available.
            available[j] = true;

        int siz = graph[n].size();
        for(int j=0; j<siz; j++){           // For all adjacent nodes.
            int v = graph[n][j];

            if(color[v] != -1)              // Adjacent colors are not available.
                available[color[v]] = false;
        }

        int c = 1;
        while(available[c] != true);         // Find lowest color which is available.
        max_color_used = max(max_color_used, c);        // Update max color used

        color[n] = c;       // Color this node.
    }
return max_color_used;      // Return color
}

bool GRAPH_COLORING::is_safe(int number_of_nodes, int color, int node)
{
    for(int i=1; i<=number_of_nodes; i++){
        if(graph[node][i] && colors[i] == color)
            return false;
    }
return true;
}

bool GRAPH_COLORING::graph_color_util(int number_of_nodes, int number_of_colors, int v)
{
    if(v == number_of_nodes)
        return true;

    for(int c=1; c<=number_of_colors; c++){
        if(is_safe(number_of_nodes, c, v)){     // Check if any adjacent nodes color match color 'c'.
            colors[v] = c;
            if(graph_color_util(number_of_nodes, number_of_colors, v+1))
                return true;
        }

        colors[c] = 0;
    }

return false;
}

void GRAPH_COLORING::color_graph_with_m_color(int number_of_nodes, int number_of_colors, int m)
{
    for(int i=1; i<=number_of_nodes; i++){      // Initially all nodes are color free
        colors[i] = 0;
    }

    if(graph_color_util(number_of_nodes, number_of_colors, m) == true)
        printf("Graph can be colored using m color's.\n");
    else
        printf("Not possible with m color's.\n");
return;
}

int main()
{

return 0;
}
