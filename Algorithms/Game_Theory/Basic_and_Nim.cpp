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
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x<y?x:y
#define MAX_VAL 30000
//int SET(int n,int i) {return (n|(1<<i));}
//int RESET(int n,int i) {return (n&~(1<<i));}
//bool check(int n,int i) {return (n&(1<<i));}
using namespace std;

//Template Ends Here


class GAME{
public:
    /*
     * If we are given single pile or single bowl from which we can take given numbers of something or
     * anything like this then we can solve it using dp array. Here the player will loss if there is
     * nothing left or he can't play his hand. We make dp array such as we make a loop of i=0 to N.
     * If a player can't play his hand then we put 0 for that index. That is called looping position.
     * If a player can make a move such that he can move to looping position then this is wining position.
     *
     * Ex.: We are given N marbels. A player can pick 2 or3 or 5 marbels at a time. If a player can't play
     * his turn the he looses. Here 0 and 1 is loosing position.
     * Solve of this is given below.
     *
     * There is many problems that can be solved using this concept with recursive dynamic programming.
     *
     * IF we are given multiple piles with different number of stone or anything like this
     * we can solve it using X-OR of number of stones in each pile. This works with a trick.
     * I know that trick :) .
     *
     *
     * Nim game:
     * Here we are given more then one pile and player can take any number of stone fron any one pile.
     * The resulr is simple. We just need to XOR all number of stone in each pile. If result is not zero
     * then player 1 will win. If result is zero then player 2 will win.
     *
     * Variation of Nim:
     *
     * Misere Nim: Here wich player will pick the last stone will loos. The previous tecnique will also
     * work for this. We just need to check is all the pails contains only a single stone then if number
     * of pile is odd then player 1 will loos else player 2 will loos.
     *
     * Pokar Nim or Bogas Nim: Here player can also add stone in pail for few time. Here everything is
     * same as original nim. If player 1 add some stone player 2 can remove same number of stone. So number
     * of stone remains same.
     *
    */
    void singlePileGameDP(int DP[], int val);
    void input_fun();
};

void GAME::singlePileGameDP(int DP[], int val)
{
    DP[0] = DP[1] = 0;  // This is looping position

    for(int i=2; i<=val; i++){
        // If we can place our oponent in any looping position then this is wining position for me
        if(DP[i-2] == 0 || DP[i-3] == 0 || DP[i-5] == 0)
            DP[i] = 1;
        else
            DP[i] = 0;
    }
//    for(int i=0; i<=val; i++)
//        cout << DP[i] << " ";
//    cout << endl;
}

void GAME::input_fun()
{
    int N = 15;
    int DP[N];

    singlePileGameDP(DP, N);

    cout << DP[N] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    GAME bc;
    bc.input_fun();
return 0;
}



