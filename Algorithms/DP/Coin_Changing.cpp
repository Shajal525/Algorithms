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
#define MAX_VAL 300
//int SET(int n,int i) {return (n|(1<<i));}
//int RESET(int n,int i) {return (n&~(1<<i));}
//bool check(int n,int i) {return (n&(1<<i));}
using namespace std;

//Template Ends Here


class COIN_CHANG{
    int DP[MAX_VAL][MAX_VAL];
public:
    /*
     * This is also known as subset sum problem.
     * In this problem we are given some coins with some value. Using this coins we have to make a given value.
     * We can use each coin as much as we like.
     * Time Complexity: O(Number of coins * Target value).
     * Memory Complexity: O(Number of coins * Target value).
     * Can be optimized to O(2 * Target value).
    */
    void input_fun();
    int coin_changing(int itms, int target, int coins[]);
    int coin_changing_iterative(int itms, int target, int coins[]);
};

int COIN_CHANG::coin_changing_iterative(int itms, int target, int coins[])
{                                          // 5, 8, 11, 15, 18
    for(int i=0; i<=itms+1; i++){
        for(int j=0; j<=target; j++){
            if(j == 0)
                DP[i][j] = 1;
            else if(i == 0)
                DP[i][j] = 0;
            else if(j < coins[i-1])
                DP[i][j] = DP[i-1][j];
            else{
                DP[i][j] = DP[i-1][j] + DP[i][j-coins[i-1]];
            }
        }
    }
    return DP[itms+1][target];
}

int COIN_CHANG::coin_changing(int itms, int target, int coins[])
{
    if(target == 0)
        return 1;
    if(itms < 0)
        return 0;
    if(DP[itms][target] != -1)
        return DP[itms][target];
//    int res = 0;
//    for(int i=0; i*coins[itms] <= target; i++){   // This is a technique
//        res += coin_changing(itms-1, target-i*coins[itms], coins);
//    }
    int res1=0,res2=0;
    if(coins[itms] <= target)
        res1 = coin_changing(itms, target-coins[itms], coins);  // This is another technique

    res2 = coin_changing(itms-1, target, coins);

    return DP[itms][target] = res1+res2;
}

void COIN_CHANG::input_fun()
{
    int coins[] = {5, 8, 11, 15, 18};
    int n = sizeof(coins)/sizeof(coins[0]);
    int target_val;
    // We just initialized DP array once. This is possible if we take target value as input and
    // try to make zero in rock_climbing function. Because we are tryig to make zero for each value.
    memset(DP, -1, sizeof(DP));

    while(cin >> target_val){
      //  cout << coin_changing_iterative(n-1, target_val, coins) << endl;
        cout << coin_changing(n-1, target_val, coins) << endl;
    }
}


int main()
{
    //ios::sync_with_stdio(false);
    cin.tie(NULL);

    COIN_CHANG bc;
    bc.input_fun();
return 0;
}

