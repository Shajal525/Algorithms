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

class Modular{
public:

    /*
     * pow(n, exp). This function will calculate this and will also calculate mod internally so
     * that overflow won't occur.
     * Time Complexity: O(log exp).
    */
    ll modular_power(ll n, ll exp, ll mod);

    /*
     * The modular multiplicative inverse is an integer ‘x’ such that
     * (a * x) % mod = 1
     *
     * The multiplicative inverse of “a modulo m” exists if and only if a and m are
     * relatively prime (if gcd(a, m) = 1).
     *
     * Input:  a = 3, m = 11
     * Output: 4
     * Since (4*3) mod 11 = 1, 4 is modulo inverse of 3
     * One might think, 15 also as a valid output as "(15*3) mod 11"
     * is also 1, but 15 is not in ring {0, 1, 2, ... 10}, so not valid.
     *
     * Nieve Approach wll take
     * Time Complexity: O(N).
    */
    /*
     * To make the algorithm efficient we can use Extended Euclidean Algorithm.
     * The idea is to use Extended Euclidean algorithms that takes two integers ‘a’ and ‘b’, finds
     * their gcd and also find ‘x’ and ‘y’ such that
     *
     * ax + by = gcd(a, b).
     *
     * To find multiplicative inverse of ‘a’ under ‘m’, we put b = m in above formula.
     * Since we know that a and m are relatively prime, we can put value of gcd as 1.
     *
     *  ax + my = 1.
     *
     * If we take modulo m on both sides, we get
     *
     *  ax + my ≡ 1 (mod m).
     *
     * We can remove the second term on left side as ‘my (mod m)’ would always be 0 for an integer y.
     *
     * ax  ≡ 1 (mod m).
     *
     * So the ‘x’ that we can find using Extended Euclid Algorithm is multiplicative inverse of ‘a’
     * Time Complexity: O(log N).
     * Referance: geeksforgeeks
    */
    int Euclidean_GCDwithCoefficient(int a, int b, int &x, int &y);
    int mod_multiplicative_inverse_nieve(int n, int mod);
    int mod_multiplicative_inverse_effi(int n, int mod);
    /*
     * Modular Division:
     * Given three positive numbers a, b and m. Compute a/b under modulo m.
     *
     * let, z = (x/y) % M.
     * We can't take z = (x%M) / (y%M). This is wrong. Instade we should take
     *
     * y_inv = findMod_Multi_Inv(y, M);
     * z = (x * y_inv) % M;
     *
     * The task is basically to find a number c such that (b * c) % m = a % m.
     *
     * Examples:
     * Input  : a  = 8, b = 4, m = 5
     * Output : 2
     *
     * Input  : a  = 8, b = 3, m = 5
     * Output : 1
     * Note that (1*3)%5 is same as 8%5.
     *
     * Modular division is defined only when modular inverse of the divisor exists.
     *
     * The task is to compute a/b under modulo m.
     * 1) First check if inverse of b under modulo m exists or not.
     *      a) If inverse doesn't exists (GCD of b and m is not 1),
     *          print "Division not defined"
     *      b) Else return  "(inverse * a) % m".
    */
    int modular_division(int a, int b, int m);

    void input_fun();
};

ll Modular::modular_power(ll n, ll exp, ll mod)
{
    ll base = n % mod;
    ll result = 1;

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

int Modular::mod_multiplicative_inverse_nieve(int n, int mod)
{
    n = n % mod;
    for(int i=1; i<n; i++){
        if(n*i % mod == 1)  // If mod is 1 then that i is the ans.
            return i;
    }
    return -1;
}

int Modular::Euclidean_GCDwithCoefficient(int a, int b, int &x, int &y)
{
    // Those are normal gcd trick.
    if(a == 0){
        x = 0;
        y = 1;
        return  b;
    }
    int x1,y1;

    int gcd = Euclidean_GCDwithCoefficient(b%a, a, x1, y1);

    // Here is the trick for finding coefficient.

    x = y1 - (b/a)*x1;
    y = x1;
    /* Calculation:
     * As seen above, x and y are results for inputs a and b,
     *    a.x + b.y = gcd                      ----(1)
     * And x1 and y1 are results for inputs b%a and a
     *    (b%a).x1 + a.y1 = gcd
     *
     * When we put b%a = (b - (⌊b/a⌋).a) in above,
     * we get following. Note that ⌊b/a⌋ is floor(a/b)
     *    (b - (⌊b/a⌋).a).x1 + a.y1  = gcd
     *
     * Above equation can also be written as below
     *    b.x1 + a.(y1 - (⌊b/a⌋).x1) = gcd      ---(2)
     *
     * After comparing coefficients of 'a' and 'b' in (1) and
     * (2), we get following
     *    x = y1 - ⌊b/a⌋ * x1
     *    y = x1
     */
    return gcd;
}

int Modular::mod_multiplicative_inverse_effi(int n, int mod)
{
    int x, y,res=-1;
    int g = Euclidean_GCDwithCoefficient(n, mod, x, y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // m is added to handle negative x
        res = (x%mod + mod) % mod;
        cout << "Modular multiplicative inverse is " << res << endl;;
    }
    return res;
}

// Find (a/b) % m.
int Modular::modular_division(int a, int b, int m)
{
    int x,y;
    a = a % m;
    int g = Euclidean_GCDwithCoefficient(b, m, x, y);

    if(g != 1){ // If GCD is not 1 then modular division is not possible.
        cout << "Inverse doesn't exists." << endl;
        return -1;
    }
    // This is the modular inverse.
    int mod_inv = (x%m + m) % m;

    // This is the formula for Modular Division.
    return (mod_inv*a) % m;
}

void Modular::input_fun()
{
    int x = 2;
    int y = 5;
    int p = 13;
    ll res = modular_power(x, y, p);
    printf("Power is %lld\n", res);

    int a = 3, m = 11;
    mod_multiplicative_inverse_effi(a, m);

    int  aa  = 8, bb = 3, mm = 5;
    cout << "Modular Division: " << modular_division(aa, bb, mm) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Modular bc;
    bc.input_fun();
return 0;
}

