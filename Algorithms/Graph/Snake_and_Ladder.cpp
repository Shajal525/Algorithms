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

class SNAKE_LADDER{
    int V;
public:

    /*
        We convert snake board into a graph. Then the shortest path length is the answer.
        Time Complexity O(N).
    */
    int snake_ladder(int moves[]);
    void input();
};


int SNAKE_LADDER::snake_ladder(int moves[])
{
    int level[V];
    int visited[V];
    for(int i=1; i<=V; i++)
        level[i] = 0,visited[i] = -1;

    queue<int> qu;
    qu.push(1);     //  Here 1 is starting position
    visited[1] = 1;

    while(!qu.empty()){
        int v = qu.front();
        qu.pop();

        for(int i=v+1; i<=v+6 && i<=V; i++){    // Move can be 1 to 6 position from previous position.

            if(visited[i] == -1){
                visited[i] = 1;
                int s = moves[i];   // Moves differs if ladder or snake exists in that position.

                level[s] = level[v] + 1;

                qu.push(s);
            }
        }
    }
return level[V];   // 30 is destination in the board
}

void SNAKE_LADDER::input()
{
    V = 30;
    int moves[V];
    for(int i=1; i<=V; i++)
        moves[i] = i;       // Initially all moves are same

     // Ladders
    moves[3] = 22;
    moves[5] = 8;
    moves[11] = 26;
    moves[20] = 29;

    // Snakes
    moves[27] = 1;
    moves[21] = 9;
    moves[17] = 4;
    moves[19] = 7;

    cout<<snake_ladder(moves);  // Answer is 3
}


int main()
{
    SNAKE_LADDER SL;
    SL.input();
return 0;
}
