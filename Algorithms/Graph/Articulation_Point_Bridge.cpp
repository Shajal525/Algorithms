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

//My Template Ends Here

using namespace std;

class ARTICULATION{
public:

    /*
        If removing a node yield two or more disjoint set of the graph then that node if articulation point.
        If removing a edge yield two or more disjoint set of the graph then that node if articulation bridge.
        Time Complexity O( V + E ).
    */
    void articulation_point(vector<int> graph[], int n);
};

const int V =  1000;
int dis[V],low[V];
int time = 0;
int root = 1;
vector<int> articulation_found;
// Light_OJ_1291(Solved). very very important. Used for finding minimum number of road to
// construct such that there is always a second way if one road is damaged.
void ARTICULATION::articulation_point(vector<int> graph[], int u)   // For bidirectional graph we have to keep track of parent
{
    low[u] = dis[u] = ++timee;

    int num_chi = 0;
    int siz = graph[u].size();
    bool f = 0;

    for(int i=0; i<siz; i++){
        int v = graph[u][i];
        if(parent[u] == v)
            continue;

        if(dis[v] != -1){
            low[u] = min(low[u], dis[v]);
        }
        else{
            num_chi++;
            parent[v] = u;
            articulation_point(graph, v);
            low[u] = min(low[u], low[v]);

            if(dis[u] <= low[v] && u != root){        // For articulation bridge or edges we have to just replace (d[u] <= low[v)
                f = 1;                                // with (d[u] < low[v]). same
            }
        }
    }
    if(f)                                       // If we insert u in insider if then u will be inserted more then once.
        articulation_found.push_back(u);

    if(num_chi > 1 && u == root)                        // No need to track root for bridge
        articulation_found.push_back(root);
return;
}

int main()
{

return 0;
}
