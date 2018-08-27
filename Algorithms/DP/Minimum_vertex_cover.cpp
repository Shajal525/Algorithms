//Template Starts Here

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
#include<bitset>
#define ll long long
#define ui unsigned int
#define MP make_pair
#define INPUT freopen("C://Users/Shajal/Desktop/input.txt", "r+", stdin)
#define OUTPUT freopen("C://Users/Shajal/Desktop/out.txt", "r+", stdout)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define sc scanf
#define pf printf
#define out cout
#define MS(x,y) memset(x,y,sizeof(x))
#define sf(x) scanf("%d", &x)
#define sff(x,y) scanf("%d %d", &x,&y)
#define sfff(x,y,z) scanf("%d %d %d", &x,&y,&z)
#define PR_CASE(x) printf("Case %d: ", x)
#define NL putchar('\n')
#define loop(i,x,y) for(int i=x;i<=y;i++)
#define PI 3.1415926535897932384626
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x<y?x:y
#define MAX_VAL 30000
//int SET(int n,int i) {return (n|(1<<i));}
//int RESET(int n,int i) {return (n&~(1<<i));}
//bool check(int n,int i) {return (n&(1<<i));}
using namespace std;

//Template Ends Here
#define MAXV 100007

class MINIMUM_VER_COV{
    int DP[MAXV][2];
    int par[MAXV];
    vector<int> graph[MAXV];
public:
    /*
     * Best algorithm for finding minimum vertex cover.
     * Time Complexity: O(N * E). I am not sure.
    */
    void input_fun();
    void initializ(int n);
    int min_vertex_cover(int a, int isGuard);
};

void MINIMUM_VER_COV::initializ(int n)
{
    for(int i=0; i<=n; i++){
        DP[i][0] = DP[i][1] = -1;
        par[i] = -1;
        graph[i].clear();
    }
}

int MINIMUM_VER_COV::min_vertex_cover(int a, int isGuard)
{
    if(graph[a].size() == 0)
        return 0;
    if(DP[a][isGuard] != -1)
        return DP[a][isGuard];

    int siz = graph[a].size();
    int sum = 0;
    for(int i=0; i<siz; i++){
        int b = graph[a][i];
        if(par[a] != b){
            if(isGuard == 0)    // If no guard present here we must protect next node with guard
                sum += min_vertex_cover(b, 1);
            else                // If already protected with a guard then we may or may not protect next node
                sum += min(min_vertex_cover(b, 0), min_vertex_cover(b, 1));
        }
    }
    return DP[a][isGuard] = sum + isGuard;
}

void MINIMUM_VER_COV::input_fun()
{
    int n;  // Number of node
    cin >> n;
    initializ(n);
    for(int i=1; i<n; i++){ // Number of edge is n-1
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int min_v_c = min(min_vertex_cover(1, 0), min_vertex_cover(1, 1));

    cout << "Minimum Vertex Cover is: " << min_v_c << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    MINIMUM_VER_COV bc;
    bc.input_fun();
return 0;
}

