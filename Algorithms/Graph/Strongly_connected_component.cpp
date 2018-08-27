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

class SCC{
public:

    /*
        This scc function use two extra function. topological_sort() and scc_util().
        First we call topological_sort then using that order and reverse graph call scc_util function.
        Then in all_scc[] array all DAG or Strongly Connected Component's are saved.
        Time Complexity is O(V + E).
    */
    void scc(vector<int> graph[], vector<int> reverse_graph[], int n);
    void topological_sort(vector<int> graph[], int n);
    void scc_util(vector<int> reverse_graph[], vector<int> all_scc[], int u, int mark);
    /*
        SCC Targan's algorithm. It takes only one DFS to find scc.
    */
    void targans_scc(vector<int> graph[], int mark);
    void targans_scc_util(vector<int> graph[], int mark);
};

stack<int> stk;
bool vis[1000];
void SCC::topological_sort(vector<int> graph[],int n)
{
    int siz = graph[n].size();
    vis[n] = true;

    for(int i=0; i<siz; i++){
        int x = graph[n][i];
        if(vis[x] == false)
            topological_sort(graph, x);
    }
    stk.push(n);
return;
}
void SCC::scc_util(vector<int> reverse_graph[], vector<int> all_scc[], int u, int mark)
{
    all_scc[mark].push_back(u);

    vis[u] = true;

    int siz = reverse_graph[u].size();

    for(int i=0; i<siz; i++){
        int v = reverse_graph[u][i];

        if(vis[v] == false)
            scc_util(reverse_graph, all_scc, v, mark);
    }
}
void SCC::scc(vector<int> graph[], vector<int> reverse_graph[], int n)
{
    vector<int> all_scc[1000];

    memset(vis, false, sizeof(vis));

    for(int i=0; i<n; i++){
        if(vis[i] == false)
            topological_sort(graph, i);
    }

    memset(vis, false, sizeof(vis));

    int mark = 0;
    while(!stk.empty()){
        int u = stk.top();
        stk.pop();

        if(vis[u] == false){
            mark++;
            scc_util(reverse_graph, all_scc, u, mark);
        }
    }
}

int mark;
int num_of_scc;
void SCC::targans_scc_util(vector<int> graph[], int now)
{
    dis[now] = low[now] = mark++;
    visited[now] = true;
    stk.push(now);
    in_stk[now] = true;

    int siz = graph[now].size();
    for(int i=0; i<siz; i++){
        int y = graph[now][i];

        if(visited[y] == false){          // If not visited simply recurse
            targans_scc_util(graph, y);

            low[now] = min(low[now], low[y]);   // Same as Articulation point/bridge
        }

        else if(in_stk[y] == true){           // Check if it's cross edge. If node is not present in stack then its cross edge
            low[now] = min(low[now], dis[y]);
        }
    }

    if(low[now] == dis[now]){   // If low and dis is same that means we find head of SCC.
        num_of_scc++;

        while(stk.top() != now){  // Pop until we reach u
            int u = stk.top();
            stk.pop();

            cout<<u<<" ";
            in_stk[u] = false;
        }
        cout<<stk.top()<<endl<<endl;
        in_stk[stk.top()] = false;
        stk.pop();
    }
}

void SCC::targans_scc(vector<int> graph[], int n)
{
    bitset<n+1> visited,in_stk;
    mark = num_of_scc = 0;

    for(int i=0; i<n; i++)
        if(visited[i] == 0)
            targans_scc_util(graph, i);


}

int main()
{

return 0;
}
