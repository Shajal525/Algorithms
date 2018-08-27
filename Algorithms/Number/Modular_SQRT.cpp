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


class SQRT_underModulo{
public:

    /*
     * Given a number ‘n’ and a prime p, find if square root of n under modulo p exists or not.
     * A number x is square root of n under modulo p if (x*x)%p = n%p.
     *
     * Examples:
     * Input:   n = 2, p = 5
     * Output:  false
     * There doesn't exist a number x such that
     * (x*x)%5 is 2
     *
     * Input:   n = 2, p = 7
     * Output:  true
     * There exists a number x such that (x*x)%7 is 2.  The number is 3.
     *
     * Time Complexity for Naive: O(P).
     *
     * Efficient Algo:
     * Square root of n under modulo p exists if and only if n^((p-1)/2) % p = 1
     *
     * Here square root of n exists means is, there exist
     * an integer x such that (x * x) % p = 1.
     *
     *
     *
     * If n is in the form 4*i + 3 with i >= 1 (OR p % 4 = 3) And
     * If Square root of n exists, then it must be
     *         ±n^((p + 1)/4).
     *
     * There is a Shanks Tonelli algorithm for finding SQRT for all p in Approximately O(log P) time.
     * That algorithm is a bit complex, so i am skipping that algorithm.
     * Ref: https://www.geeksforgeeks.org/find-square-root-modulo-p-set-2-shanks-tonelli-algorithm/ .
    */
    bool squareRootExists_Naive(int n, int p);
    int modular_power(int n, int exp, int mod);
    bool squareRootExists(int n, int p);
    void squareRoot(int n, int p);
    void input_fun();
};

bool SQRT_underModulo::squareRootExists_Naive(int n, int p)
{
    n = n%p;

    // One by one check all numbers from 2 to p-1
    for (int x=2; x<p; x++)
        if ((x*x)%p == n)
            return true;
    return false;
}

int SQRT_underModulo::modular_power(int n, int exp, int mod)
{
    int base = n % mod;
    int result = 1;

    while(exp > 0){

        // If Exponent is odd we multiply this with result
        // This will be true at lease once when exp = 1.
        // here we use he property n^6 = (n^2)3 and n^7 = n * n^6.
        if(exp & 1){
            result = (result * base) % mod;
        }

        exp = exp >> 1; // Divide exp by 2

        base = (base * base) % mod; // Base square.
    }

    return result;
}

bool SQRT_underModulo::squareRootExists(int n, int p)
{
    // Check for Euler's criterion that is
    // [n ^ ((p-1)/2)] % p is 1 or not.
    if (modular_power(n, (p-1)/2, p) == 1)
       return true;

    return false;
}

// Utility function to do modular exponentiation.
// It returns (x^y) % p.
int power(int x, int y, int p)
{
    int res = 1; // Initialize result
    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns true if square root of n under modulo p exists
// Assumption: p is of the form 3*i + 4 where i >= 1
void SQRT_underModulo::squareRoot(int n, int p)
{
    if (p % 4 != 3) {
        cout << "Invalid Input";
        return;
    }

    // Try "+(n^((p + 1)/4))"
    n = n % p;
    int x = modular_power(n, (p + 1) / 4, p);

    // This is is sqrt if this condition becomes true.
    if ((x * x) % p == n) {
        cout << "Square root is " << x << endl;
        return;
    }

    // If that is not the ans
    // Try "-(n ^ ((p + 1)/4))"
    x = p - x;
    if ((x * x) % p == n) {
        cout << "Square root is " << x << endl;
        return;
    }

    // If none of the above two work, then
    // square root doesn't exist
    cout << "Square root doesn't exist " << endl;
}

void SQRT_underModulo::input_fun()
{
    int p = 7;
    int n = 2;
    squareRootExists_Naive(n, p)? cout << "Yes" << endl : cout << "No" << endl;

    squareRootExists(n, p)? cout << "Yes" << endl: cout << "No" << endl;


    squareRoot(n, p);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    SQRT_underModulo bc;
    bc.input_fun();
return 0;
}

