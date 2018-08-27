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

class Modulas_Trick{
public:
    /*
     * Multiply Big numbers:
     * Suppose A and B are two big numbers. We want to calculate (A * B) % M.
     *
     * Now A*B may cause overflow. That is the problem.
     * We can write a * b = a + a + … + a (b times).
     * But this will take O(B) time.
     *
     * Better way to do this is
     * If b is even then
     *      a * b = 2 * a * (b / 2),
     * otherwise
     *      a * b = a + a * (b - 1).
     *
     * Now Time Complexity is: O(log B).
     *
    */
    long long multiply_two_big_numbers(long long a, long long b, long long mod);
    /*
     * Sum of 1 to N modulo K:
     *
     * Example:
     * Input : N = 10 and K = 2.
     * Output : 5
     * Sum = 1%2 + 2%2 + 3%2 + 4%2 + 5%2 + 6%2 + 7%2 + 8%2 + 9%2 + 10%2
     *     = 1 + 0 + 1 + 0 + 1 + 0 + 1 + 0 + 1 + 0 = 5.
     *
     * Algorithm:
     * Case 1: If N < K, if i= 1_to_n, for all i, i%K = i. So, The sum will be N(N+1)/2.
     *
     * Case 2: When N >= K, then integers from 1 to K in natural number sequence will produce,
     *         1, 2, 3, ….., K – 1, 0 as result when operate with modulo K. Similarly,
     *         from K + 1 to 2K, it will produce same result. So, the idea is to count how many
     *         number of times this sequence appears and multiply it with sum of first K – 1 natural numbers.
     *
    */
    ll sumOf_1toN_mod_m(int n, int mod);
    // Calclate mod for each digit. Check implementation.
    int mod_of_bitNumber(string st, int m);
    /*
     * If we need to find power of power, like (A^(B^C)) % M, then the formula is
     *      y = (B^C) % (M-1).
     *      ans = (A^y) % M.
     * Implementation is easy.
    */
    void input_fun();
};


ll Modulas_Trick::multiply_two_big_numbers(ll a, ll b, ll mod)
{
    a = a % mod;

//  Just implement:
//    If b is even then
//      a * b = 2 * a * (b / 2),
//    otherwise
//      a * b = a + a * (b - 1).
    // This works like recursion. Each time calculate a and then treat b/2 as new number.

    long long res = 0;
    while(b){

        // If B is odd add a with result.
        if(b & 1){
            res = (res + a) % mod;
            b--;    // Optional
        }

        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;
        b >>= 1;    // b /= 2
    }

    return res; // A is already added to res when b=1.
}

ll Modulas_Trick::sumOf_1toN_mod_m(int n, int mod)
{
    ll ans;

    // Counting the number of times 1, 2, ..,
    // K-1, 0 sequence occurs.
    ll x = n/mod;

    // Number of last few numbers.
    ll y = n % mod;

    // Sequence occures as 1, 2, 3, ….., K – 1, 0.
    // So, sum from 1 to k-1 = (k-1)(k-1+1)/2 = (k-1)(k)/2.
    ll sum_1toMOD = mod*(mod-1)/2;

    // Now, sum of 1 to y = y(y+1)/2.
    ll sum_1toY = y*(y+1)/2;

    ans = x * sum_1toMOD + sum_1toY;
    return ans;
}

int Modulas_Trick::mod_of_bitNumber(string st, int m)
{
    int res = 0;
    int len = st.length();

    // Check each letter left to right.
    for(int i=0; i<len; i++){
        int dig = st[i] - '0';

        res = (res * 10 + dig) % m;
    }
    return res;
}

void Modulas_Trick::input_fun()
{
    long long a = 10123465234878998;
    long long b = 65746311545646431;
    long long m = 10005412336548794;
    cout << multiply_two_big_numbers(a, b,m) << endl;

    int N = 10, K = 2;
    cout << sumOf_1toN_mod_m(N, K) << endl;

    string num = "12316767678678";
    cout << mod_of_bitNumber(num, 10) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Modulas_Trick bc;
    bc.input_fun();
return 0;
}

