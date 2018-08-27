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
#define ll long long

class BinomialCoefficient{
public:
    /*
     * Binomial Coefficient is nCr.
     * A binomial coefficient C(n, k) gives the number of ways,
     * disregarding order, that k objects can be chosen from among n objects;
     * more formally, the number of k-element subsets (or k-combinations) of an n-element set.
     *
     * Recursive formula for calculating nCr is:
     *   C(n, k) = C(n-1, k-1) + C(n-1, k).
     *   C(n, 0) = C(n, n) = 1.
     * This is done using DP.
     * Time Complexity: O(N*R).
     * Space Complexity: O(N*R). If we don't want save values then Spcae Complexity will be O(N).
     *
     * In efficient method
     * Time Complexity: O(R).
     * Space Complexity: O(1).
    */
    void nCr_DP(ll nCr[][1009], int n, int r);
    int nCr_Efficient(int n, int r);
    void input_fun();
};

void BinomialCoefficient::nCr_DP(ll nCr[][1009], int n, int r)
{
    for(int i=0; i<=n; i++){
        for(int j=0; j<=min(i,r); j++){
            if(i == 0 || i == j || j == 0)
                nCr[i][j] = 1;
            else{
                nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
            }
        }
    }
}

int BinomialCoefficient::nCr_Efficient(int n, int r)
{
    // We know that, C(n, k) = C(n, n-k)
    if(r > n-r)
        r = n-r;

    // Simple calculation for simplified formula.
    //    C(n, k) = n! / (n-k)! * k!
    //            = [n * (n-1) *....* 1]  / [ ( (n-k) * (n-k-1) * .... * 1) *
    //                                        ( k * (k-1) * .... * 1 ) ]
    //    After simplifying, we get
    //    C(n, k) = [n * (n-1) * .... * (n-k+1)] / [k * (k-1) * .... * 1]
    int result = 1;
    for(int i=0; i<r; i++){
        result *= (n-i);        // Calcuate [n * (n-1) * .... * (n-k+1)] part
        result /= (i+1);        // Calculate [k * (k-1) * .... * 1] part.
    }

    return result;
}

void BinomialCoefficient::input_fun()
{
    ll nCr[1009][1009];

    nCr_DP(nCr, 100, 100);

    for(int i=0; i<=10; i++)
        for(int j=0; j<=i; j++){
            cout << "DP: " << i << "-C-" << j << " = " << nCr[i][j] << endl;
            cout << "Ef: " << i << "-C-" << j << " = " << nCr_Efficient(i,j) << endl;
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    BinomialCoefficient bc;
    bc.input_fun();
return 0;
}

