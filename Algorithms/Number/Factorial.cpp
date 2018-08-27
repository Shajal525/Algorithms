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


class Factorial{
public:
    /*
     * Legendre’s formula (Given p and n, find the largest x such that p^x divides n!):
     *
     * Input:  n = 7, p = 3
     * Output: x = 2
     * 32 divides 7! and 2 is the largest such power of 3.
     *
     * Normal algorithm may not work because we may not count factorial for big numbers.
     *
     * The formula is  exp = n/p + n/(p^2) + n/(p^3) + ....
     * Basically we find out number of p from (1 to n).
     * This only works when P is prime.
     *
     * What to do if p is not prime?
     * We can find all prime factors of p and compute result for every prime factor.
     * Then find min power among all factors.
     *
     * Time Complexity: O(log N) when P is prime.
     *
     */
    int largestPower(int n, int p); // This works when p is Prime.

    vector<pair<int, int> > primeFactors(int k);
    int largestPower_anyP(int n, int p);

    /*
     * We need an importent formula called Divisor Formula:
     * When P is prime sum of 0 to N th power of P is
     * 1 + p^1 + p^2 + p^3 + ...... + p^N = ((p^(n+1)) - 1) / (p-1).
     *
     * We already know that:
     * Consider the number 18.

//        Sum of factors = 1 + 2 + 3 + 6 + 9 + 18

//        Writing divisors as powers of prime factors.
//        Sum of factors = (2^0)(3^0) + (2^1)(3^0) + (2^0)(3^1) +
//                         (2^1)(3^1) + (2^0)(3^2) + (2^1)(3^2)
//                       = (2^0)(3^0) + (2^0)(3^1) + (2^0)(3^2) +
//                         (2^1)(3^0) + (2^1)(3^1) + (2^1)(3^2)
//                       = (2^0)(3^0 + 3^1 + 3^2) +
//                         (2^1)(3^0 + 3^1 + 3^2)
//                       = (2^0 + 2^1)(3^0 + 3^1 + 3^2).
    *
    * Sum of divisors of factorial of a number: N!
    *
    * The idea is, we find all the prime numbers from 2 to N. After that we need to
    * calculate highest power of each prime number and calculate sum using above two formula.
    *
    * To calculate number of factors we need to multiply exponent+1 for each prime factors.
    * Ex. (exp1+1)*(exp2+1)*(exp3+1)*......*(expN+1).
    */
    vector<int> sieve(int n);
    int sumOf_divisorsOf_factorial(int n);
    void input_fun();
};

int Factorial::largestPower(int n, int p)
{
    int exp = 0;
    int tp = p;

    // Calculate x = n/p + n/(p^2) + n/(p^3) + ....
    while(n>=tp){
        exp += (n/tp);
        tp =  tp * p;
    }

    return exp;
}

// returns all the prime factors of k
vector<pair<int, int> > Factorial::primeFactors(int k)
{
    // vector to store all the prime factors
    // along with their number of occurrence
    // in factorization of k
    vector<pair<int, int> > ans;

    for (int i = 2; k != 1; i++) {
        if (k % i == 0) {
            int count = 0;
            while (k % i == 0) {
                k = k / i;
                count++;        // We need count of each prime factor
            }

            ans.push_back(make_pair(i, count));
        }
    }
    return ans;
}

// Returns largest power of k that
// divides n!
int Factorial::largestPower_anyP(int n, int p)
{
    vector<pair<int, int> > vec;
    vec = primeFactors(p);
    int ans = INT_MAX;
    for (int i = 0; i < (int)vec.size(); i++)

        // calculating minimum power among all
        // the prime factors of k.
        ans = min(ans, largestPower(n,  vec[i].first) / vec[i].second);

    return ans;
}

vector<int> Factorial::sieve(int n)
{
    // Create a boolean array "prime[0..n]" and
    // initialize all entries it as true. A value
    // in prime[i] will finally be false if i is
    // not a prime, else true.
    vector<bool> prime(n+1, true);
    vector<int> allPrimes;

    // Loop to update prime[]
    for (int p = 2; p*p <= n; p++)
    {
        // If prime[p] is not changed, then it
        // is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i = p*2; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Store primes in the vector allPrimes
    for (int p = 2; p <= n; p++)
        if (prime[p])
            allPrimes.push_back(p);

    return allPrimes;
}

int Factorial::sumOf_divisorsOf_factorial(int n)
{
    vector<int> allPrimes;
    allPrimes = sieve(n);  // create sieve

    // Initialize result
    int result = 1;

    // find exponents of all primes which divides n
    // and less than n
    for (int i = 0; i < (int)allPrimes.size(); i++)
    {
        // Current divisor
        int p = allPrimes[i];

        // Find the highest power (stored in exp)'
        // of allPrimes[i] that divides n using
        // Legendre's formula.
        int exp = 0;
        while (p <= n)
        {
            exp = exp + (n/p);
            p = p*allPrimes[i];
        }

        // Using the divisor function to calculate the sum
        // 1 + p^1 + p^2 + p^3 + ...... + p^N = ((p^(n+1)) - 1) / (p-1).
        result = result*(pow(allPrimes[i], exp+1)-1)/(allPrimes[i]-1);
     }

    // return total divisors
    return result;
}

void Factorial::input_fun()
{
    int n = 10, p = 3;
    printf("The largest power of %d that divides %d! is %d\n",
           p, n, largestPower(n, p));                           // Ans 4

    cout << largestPower_anyP(7, 2) << endl;    // Ans 4
    cout << largestPower_anyP(10, 9) << endl;   // Ans 2

    cout << sumOf_divisorsOf_factorial(4) << endl;  // Ans 60
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Factorial bc;
    bc.input_fun();
return 0;
}


