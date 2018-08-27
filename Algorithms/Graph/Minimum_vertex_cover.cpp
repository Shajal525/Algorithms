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

class MINIMUM_VER_COV{
    int dp[1000][2];
    int par[1000];
public:
    int minimum_vertex_cover(vector<int> graph[], int s, int is_ga);
};

int MINIMUM_VER_COV::minimum_vertex_cover(vector<int> graph[], int s, int is_ga)
{
    if(dp[s][is_ga] != -1)              // dp array should be initialized to minus one.
        return dp[s][is_ga];

    int siz = graph[s].size();

    int cou = 0;

    for(int i=0; i<siz; i++){
        int d = graph[s][i];

        if(par[s] == d)
            continue;

        par[d] = s;

        if(is_ga == 0)                                          // If guard is not present at this node we must take guard in next node.
            cou += minimum_vertex_cover(graph, d, 1);
        else if(is_ga == 1)                                     // If guard is preset at this node then we will try both in next
            cou += min(minimum_vertex_cover(graph, d, 1), minimum_vertex_cover(graph, d, 0));   // node and take the minimum.
    }
return cou + is_ga;
}

int main()
{

return 0;
}
