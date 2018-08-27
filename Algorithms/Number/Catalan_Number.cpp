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

class Catalan{
public:

    /*
     * Catalan number is s sequence that accure in may countig problem.
     * The sequence is  1,1,2,5,14,42,132,429 ..........
     * DP solution will take O(N*N) time
     *
     * Binomial coefficient method will take O(N) time.
     *
     * The formula is:
     * Catalan(n) = (1/(n+1)) * nCr(2*n, n).
     *            = nCr(2n, n)/(n+1).
     *
     * There is many application of Catalan number.
     * One application is number of BST possible with N nodes.
     * https://www.geeksforgeeks.org/applications-of-catalan-numbers/
     * This page is very importent. I should prin it. There is a lot of application o catalan number.
    */
    ll CatalanDP(ll cat[], int n);
    ll BinomialCoefficient_nCr(int n, int r);
    ll CatalanNumberBinomial(int n);
    void input_fun();
};

ll Catalan::CatalanDP(ll cat[], int n)
{
    cat[0] = cat[1] = 1;

    for(int i=2; i<=n; i++){
        cat[i] = 0;

        for(int j=0; j<i; j++)
            cat[i] += (cat[j] * cat[i-j-1]);
    }
    return cat[n];

}

ll Catalan::BinomialCoefficient_nCr(int n, int r)
{
    if(r > n-r)
        r = n-r;

    ll result = 1;
    for(ll i=0; i<r; i++){
        result *= (n-i);
        result /= (i+1);
    }
    return result;
}

ll Catalan::CatalanNumberBinomial(int n)
{
    // Calculate nCr(2*n, n).
    ll binomial = BinomialCoefficient_nCr(2*n, n);

    // Divide nCr(2*n, n) by (n+1).
    return binomial/(n+1);
}

void Catalan::input_fun()
{
    for (int i = 0; i < 10; i++)
        cout << CatalanNumberBinomial(i) << " " ;
    cout << endl;

    ll cat[1009];
    CatalanDP(cat, 1000);

    for (int i = 0; i < 10; i++)
        cout << cat[i] << " " ;

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Catalan bc;
    bc.input_fun();
return 0;
}

