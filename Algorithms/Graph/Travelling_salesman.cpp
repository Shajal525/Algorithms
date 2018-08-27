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
#define INF INT_MAX
//int SET(int n,int i) {return (n|(1<<i));}
//int RESET(int n,int i) {return (n&~(1<<i));}
inline bool check(int n,int i) {return (n&(1<<i));}
using namespace std;

//My Template Ends Here


class TRAVELLING_SALESMAN{
    const static int V = 100;
    int graph[V][V];
    int source_to_i_via_set_j[V][V];
    pair<int, int> parent[V][V];
    vector<int> full_set;
    vector<vector<int> >  subsets;
public:
    /*
     *  Given some node and edge. From a node we need visite each node once and come bcak to source node
     *  with minimum cost.
        Hamilton circuit is same as Traveling Salesman.
        Here we need to find minimum cost Hamilton circuit.
        We can also find Hamiltonian path using this algorithm.

        Traveling salesman recursive algorithm which has time Complexity of O(N!).
        This is a O((N*N) * (2^N)) algorithm but it is tough to implement. :(
        Reference : Tushar.
    */
    int travelling_salesman();
    void all_subset(int n);
    void subset_rec(int i, int l, int siz, vector<int> st);
    void all_subset_iterative(int n);
    void input_fun();
    void print_path(int source, int mp_v);
};

void TRAVELLING_SALESMAN::subset_rec(int i, int l, int siz, vector<int> vt)
{
    if((int)vt.size() == l){
        subsets.push_back(vt);
        return;
    }
    if(i >= siz)
        return;

    // Similar as 0-1 napsak.
    vt.push_back(full_set[i]);
    subset_rec(i+1, l, siz, vt);
    vt.pop_back();
    subset_rec(i+1, l, siz, vt);

return;
}

void TRAVELLING_SALESMAN::all_subset(int siz)
{

    for(int l=1; l<=siz; l++){
        vector<int> st;
        subset_rec(0, l, siz, st);  // Find all combination of length l.
    }

return;
}

void TRAVELLING_SALESMAN::all_subset_iterative(int n)
{
    int mask = 1;

    int range = 1<<n;

    // Number of Subset of n number is 2^n.
    // Here mask's binary representation from 1 to 1<<n contains all combination in binary form
    while(mask < range){
        vector<int> st;
        for(int i=0; i<n; i++){
            if(check(mask, i))  // If this bit it 1 then we take this
                st.push_back(full_set[i]);
        }

        subsets.push_back(st);
        mask++;
    }
return;
}

void TRAVELLING_SALESMAN::print_path(int source, int mp_v)
{
    int sss = source;
    cout<<sss<<"-> ";
    while(parent[source][mp_v].first){
        int s = source;
        cout<<parent[s][mp_v].first<<"-> ";
        source = parent[s][mp_v].first;
        mp_v = parent[s][mp_v].second;
    }
    cout<<sss<<endl;
}

int TRAVELLING_SALESMAN::travelling_salesman()          // Source is 1.
{
    map<vector<int>, int> mp;
    vector<vector<int> >::iterator it;
    int source = 1;
    int n = full_set.size();

    all_subset(full_set.size());      // Subset of full set. Sequence problem in Iterative version
    int t=1;

    for(it = subsets.begin(); it != subsets.end(); it++){       // Map all subsets as integer. Can be done with iterator
        mp[*it] = t++;
    }

    for(int i=2; i<=n; i++){                                // Source to all other node via empty set.
        source_to_i_via_set_j[i][0] = graph[source][i];
        parent[i][0] = make_pair(0, 0);
    }

    for(it = subsets.begin(); it != subsets.end(); it++){       // for all subset. Can be done without iterator.

        for(int j=2; j<=n+1; j++){                              // Source to all nodes via this set
            if(find((*it).begin(), (*it).end(), j) != (*it).end())      // If this set contains node j
                continue;
            int siz = (*it).size();

            if(siz == 1){       // If size is one then we don't have to find min. Just source to j node via set's one element

                source_to_i_via_set_j[j][mp[*it]] = graph[source][(*it)[0]] + graph[(*it)[0]][j];
                parent[j][mp[*it]] = make_pair((*it)[0], 0);
            }
            else{
                int minn = INT_MAX;

                for(int k=0; k<siz; k++){
                    vector<int> vv;
                    for(int p=0; p<siz; p++){
                        if(p!=k)
                            vv.push_back((*it)[p]);
                    }
                    int ss = (*it)[k];
                    int ttt = graph[ss][j] + source_to_i_via_set_j[ss][mp[vv]];

                    if(ttt<minn){
                        minn = ttt;
                        parent[j][mp[*it]] = make_pair(ss, mp[vv]);
                    }
                }
                source_to_i_via_set_j[j][mp[*it]] = minn;
            }
        }
    }
    // For finding source to source cost via set of all other nodes.
    it--;
    int siz = (*it).size();

    int minn = INT_MAX;

    for(int k=0; k<siz; k++){
        vector<int> vv;
        for(int p=0; p<siz; p++){
            if(p!=k)
                vv.push_back((*it)[p]);
        }
        int ss = (*it)[k];
        int ttt = graph[ss][source] + source_to_i_via_set_j[ss][mp[vv]];
        if(ttt<minn){
            minn = ttt;
            parent[source][mp[*it]] = make_pair(ss, mp[vv]);
        }
    }
    source_to_i_via_set_j[source][mp[*it]] = minn;

return source_to_i_via_set_j[source][mp[*it]];
}

void TRAVELLING_SALESMAN::input_fun()
{
//    int n,e,a,b,w;
//    memset(graph, INT_MAX, sizeof(graph));     // Initialize as INF.
//    cin>>n>>e;
//
//    for(int i=1; i<=n; i++){
//        full_set.push_back(i);            // Make a set of all nodes without source.
//        graph[i][i] = 0;
//    }
//
//    while(e--){
//        cin>>a>>b>>w;
//        graph[a][b] = w;
//    }

    int m,n = 4;
    for(int i=2; i<=n; i++){
        full_set.push_back(i);
        graph[i][i] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=4; j++){
            cin>>m;
            graph[i][j] = m;
        }
    }

    cout<<travelling_salesman()<<endl;

    int source = 1;
    print_path(source, (1<<(n-1))-1);
}


int main()
{
    INPUT;
    TRAVELLING_SALESMAN TS;
    TS.input_fun();

return 0;
}


/*

0 1 15 6
2 0 7 3
9 6 0 12
10 4 8 0

*/

