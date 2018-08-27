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

class KNAPSACK{
    int *cost;
    int *weight;
    int **DP;
public:
    /*
     * 0-1 Knapsack problem
     * Time complexity: O(N * M).
     * Here N = Number of items and M = maximum weight capacity.
    */
    void input_fun();
    int knapsack(int w, int n);
    int knapsack_util(int w, int n);
    int knapsack_iterative(int wt, int num_itm);
    void print_result(int wt, int num_itm);
};

void KNAPSACK::print_result(int wt, int num_itm)
{
    cout << "Piked items are: ";
    while(wt > 0 && num_itm > 0){
        if(DP[num_itm][wt] != DP[num_itm-1][wt]){
            cout << num_itm << " ";
            wt -= weight[num_itm-1];
        }
        num_itm--;
    }
    cout << endl;
}

int KNAPSACK::knapsack_iterative(int wt, int num_itm)
{
    for(int i=0; i<=num_itm; i++){
        for(int w=0; w<=wt; w++){
            if(w==0 || i==0)
                DP[i][w] = 0;
            else if(weight[i-1] <= w)
                DP[i][w] = max(cost[i-1] + DP[i-1][w-weight[i-1]], DP[i-1][w]);
            else
                DP[i][w] = DP[i-1][w];
        }
    }
    return DP[num_itm][wt];
}

int KNAPSACK::knapsack_util(int w, int n)
{
    if(n <= 0 || w == 0)
        return 0;
    if(DP[n][w] != -1)
        return DP[n][w];

    int profit1, profit2;
    if(weight[n-1] <= w)
        profit1 = cost[n-1] + knapsack_util(w-weight[n-1], n-1);
    else
        profit1 = 0;
    profit2 = knapsack_util(w, n-1);

    return DP[n][w]=max(profit1, profit2);
}

int KNAPSACK::knapsack(int w, int n)
{
    DP = (int **)malloc(sizeof(int)*(n+5));

    for(int i=0;i<=n+2;i++){
        DP[i] = (int *)malloc(sizeof(int)*(w+5));
        for(int j=0; j<=w; j++)
            DP[i][j] = -1;
    }
    return knapsack_util(w, n);
   // return knapsack_iterative(w, n);
}

void KNAPSACK::input_fun()
{
    int items = 4;
    int total_capacity = 10;
    cost = (int *)malloc(sizeof(int) * items);
    weight = (int *) malloc(sizeof(int) * total_capacity);
    cost[0] = 120, cost[1] = 280, cost[2] = 150, cost[3] = 200;
    weight[0] = 1, weight[1] = 4, weight[2] = 3, weight[3] = 4;

    cout << knapsack(total_capacity, items) << endl;
    print_result(total_capacity, items);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    KNAPSACK bc;
    bc.input_fun();
return 0;
}

