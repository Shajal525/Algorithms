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
#include<unordered_set>
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


class Eular_Phi{
public:
    /*
     * Euler’s Totient function P(n) for an input n is count of numbers in {1, 2, 3, …, n}
     * that are relatively prime to n, i.e., the numbers whose GCD with n is 1.
     * Naive approach will take O(N) time.
     *
     * There is a better solution. The formula basically says that the value of P(n) is
     * equal to n multiplied by product of (1 – 1/p) where p is all prime factors of n.
     * For example prime factor of 6 is {2,3}, value of P(6) = 6 * (1-1/2) * (1 – 1/3) = 2.
     *
     * P(N) = N*(1-1/p1)*(1-1/p2).......  where p is all prime factors of n.
     * We can write it as P(N) = (N-N/P)*(1-1/P).......
     * Time complexity: O(sqrt(N)).
     *
     * If we have a lot of quary then we can use another algorithm which can calculate Phi
     * for all number from 1 to n.
     * There is few importent properties of Eular Phi in geeksforgeeks.
     * Time Complexity: O(N log N). Not sure.
    */
    float eularPhiEffi(int n);
    int eularPhiFor1toN(int phi[], int n);
    /*
     * Primitive root of a prime number n modulo n:
     * Given a prime number n, the task is to find its primitive root under modulo n.
     * Primitive root of a prime number n is an integer r between[1, n-1] such that the
     * values of r^x(mod n) where x is in range[0, n-2] are different. Return -1 if n is a
     * non-prime number.
     * Input : 7
     * Output : Smallest primitive root = 3
     *      Explanation: n = 7
     *          3^0(mod 7) = 1
     *          3^1(mod 7) = 3
     *          3^2(mod 7) = 2
     *          3^3(mod 7) = 6
     *          3^4(mod 7) = 4
     *          3^5(mod 7) = 5
     *
     * Input : 761
     * Output : Smallest primitive root = 6.
     *
     * This is an efficient algorithm.
     * Referance: geeksforgeeks.
     * Time Complexity: O(N log N).
    */
    bool isPrime(int n);
    int power(int x, unsigned int y, int p);
    void findPrimefactors(unordered_set<int> &s, int n);
    int findPrimitive(int n);
    void input_fun();
};

float Eular_Phi::eularPhiEffi(int n)
{
    float result = n;

    for(int p=2; p*p<=n; p++){
        if(n%p == 0){
            while(n%p == 0)
                n /= p;

            // Both are same but in below implementation we don't have to deal with floating numbers.

            // result = result * (1.0 - (1.0 / (float)p));
            result = result - result / p;
        }
    }
    // If n has a prime factor greater than sqrt(n)
    // That means n is prime
    if (n > 1){
        //result *= (1.0 - (1.0 / (float)n));
        result = result - result / n;
    }
    return result;
}

int Eular_Phi::eularPhiFor1toN(int phi[], int n)
{
    // Initializ phi[] with i
    for(int i=0; i<=n; i++)
        phi[i] = i;

    // This part is Sieve.
    for(int i=2; i<=n; i++){

        // If phi[i]=i that means phi[i] is not modified yet, that means i is prime.
        if(phi[i] == i){

            // For prime Phi[i] = i-1.
            phi[i] = i-1;

            // Calculate phi for all numbers where i is a factor
            for(int j=2*i; j<=n; j+=i)
                phi[j] = (phi[j] - phi[j]/i);
        }
    }
    return phi[n];
}

// Returns true if n is prime
bool Eular_Phi::isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;

    return true;
}

/* Iterative Function to calculate (x^n)%p in
   O(logy) */
int Eular_Phi::power(int x, unsigned int y, int p)
{
    int res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// Utility function to store prime factors of a number
void Eular_Phi::findPrimefactors(unordered_set<int> &s, int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        s.insert(2);
        n = n/2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            s.insert(i);
            n = n/i;
        }
    }

    // This condition is to handle the case when
    // n is a prime number greater than 2
    if (n > 2)
        s.insert(n);
}

// Function to find smallest primitive root of n
int Eular_Phi::findPrimitive(int n)
{
    unordered_set<int> s;

    // Check if n is prime or not
    if (isPrime(n)==false)
        return -1;

    // Find value of Euler Totient function of n
    // Since n is a prime number, the value of Euler
    // Totient function is n-1 as there are n-1
    // relatively prime numbers.
    int phi = n-1;

    // Find prime factors of phi and store in a set
    findPrimefactors(s, phi);

    // Check for every number from 2 to phi
    for (int r=2; r<=phi; r++)
    {
        // Iterate through all prime factors of phi.
        // and check if we found a power with value 1
        bool flag = false;
        for (auto it = s.begin(); it != s.end(); it++)
        {

            // Check if r^((phi)/primefactors) mod n
            // is 1 or not
            if (power(r, phi/(*it), n) == 1)
            {
                flag = true;
                break;
            }
         }

         // If there was no power with value 1.
         if (flag == false)
           return r;
    }

    // If no primitive root found
    return -1;
}


void Eular_Phi::input_fun()
{
    int n;
    for (n = 1; n <= 10; n++)
        printf("phi(%d) = %d\n", n, (int)eularPhiEffi(n));

    n=100;
    int phi[n+5];

    eularPhiFor1toN(phi, n);

    for (int i=1; i<=10; i++)
          cout << "Totient of " << i << " is "
               << phi[i] << endl;

    cout << endl;

    n = 761;
    cout << " Smallest primitive root of " << n
             << " is " << findPrimitive(n) << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Eular_Phi bc;
    bc.input_fun();
return 0;
}

