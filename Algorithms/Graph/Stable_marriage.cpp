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

class STABLE{
public:
    void stable_merriage(vector<int> man_pre[], vector<int> wom_pre[], int num_man, int num_wom);
};

void STABLE::stable_merriage(vector<int> man_pre[], vector<int> wom_pre[], int num_man, int num_wom)
{
    queue<int> qu;
    int wom_coupled_with[num_man];
    bool wom_free[num_wom];
    bool man_free[num_man];

    for(int i=1; i<=num_man; i++){              // Pushing all men in queue.
        qu.push(i);
        wom_free[i] = man_free[i] = true;       // Initially all man and womans are free.
    }

    while(!qu.empty()){                          // Until there is no free man
        int m = qu.front();
        qu.pop();

        for(int i=0; i<num_wom; i++){             // man's preference list
            int w = man_pre[m][i];

            if(wom_free[w] == true){                // If that woman free make couple and stop
                wom_coupled_with[w] = m;
                break;
            }
            else{
                bool f = 0;
                for(int i=0; i<num_man && wom_pre[w][i] != wom_coupled_with[w]; i++){
                    if(wom_pre[w][i] == m){                     // If that woman prefer this man more.
                        f = 1;
                        int man_freed = wom_coupled_with[w];    // Break previous marriage

                        wom_coupled_with[w] = m;                // Make new marriage

                        qu.push(man_freed);                     // Push freed man gain in queue
                        break;
                    }
                }
                if(f)
                    break;
            }
        }
    }
return;
}

int main()
{

return 0;
}
