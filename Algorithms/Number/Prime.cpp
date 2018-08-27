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


class Prime{
public:
    /*
     * Wilson’s Theorem
     *      Wilson’s theorem states that a natural number p > 1 is a prime number if and only if
     *
     *     (p - 1) ! ≡  -1   mod p
     * OR  (p - 1) ! ≡  (p-1) mod p
     *
     * Examples:
     * p  = 5
     * (p-1)! = 24
     * 24 % 5  = 4
     *
     * p  = 7
     * (p-1)! = 6! = 720
     * 720 % 7  = 6
     *
     * We can't use this property to check if a number is prime or not. Because complex numbers also can
     * have remainder 1 or (p-1).
     *
     * To check if a number is prime or not, Basic algorithm is given below.
    */
    bool isPrime(int n);\
    /*
     * There is also some other method to check if anumber is prime or not but those
     * formulas are based on probability. Ex: Solovay-Strassen, Miller–Rabin, Fermat-method.
     * So we should not use them.
    */
    void input_fun();
};

bool Prime::isPrime(int n)
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

void Prime::input_fun()
{
    isPrime(11)?  cout << " true\n": cout << " false\n";
    isPrime(15)?  cout << " true\n": cout << " false\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Prime bc;
    bc.input_fun();
return 0;
}

