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


class PolitenessOfNumber{
public:
    /*
     * Politeness of a number is defined as the number of ways
     * it can be expressed as the sum of consecutive integers.
     * Input: n = 15
     * Output: 3
     * Explanation:
     * There are only three ways to express
     * 15 as sum of consecutive integers i.e.,
     * 15 = 1 + 2 + 3 + 4 + 5
     * 15 = 4 + 5 + 6
     * 15 = 7 + 8
     * Hence answer is 3.
     * Nieve approach will take O(N^2) time.
     * There is an efficient way to do this. There is a prove that Total number of odd
     * factors (except 1) of a number is equal to politeness of the number.
     * In general if a number can be represented as ap * bq * cr … where a, b, c, … are
     * prime factors of n. If a = 2 (even) then discard it and b and c is odd so total number of odd
     * factors which can be written as [(q + 1) * (r + 1) * …] – 1.
     * Here 1 is subtracted because we will not count 1 as factor of n.
     *
    */

    int politeness(int n);
    void input_fun();
};

int PolitenessOfNumber::politeness(int n)
{
    int result = 1;

    // Eliminate all even prime factor of number of n
    while(!n&1)
        n/=2;

    // n must be odd at this point, so iterate for only
    // odd numbers till sqrt(n)
    for(int i=3; i*i<=n; i+=2){

        int divCount = 0;

        // if i divides n, then start counting of odd divisors
        while(n%i == 0){
            n /= i;
            divCount++;
        }
        // According to the formula.
        result *= (divCount + 1);
    }

    // If n odd prime still remains then count it
    if(n > 2)
        result *= 2;

    return result - 1;
}

void PolitenessOfNumber::input_fun()
{
    int n = 90;
    cout << "Politness of " << n << " = " << politeness(n) << "\n";

    n = 15;
    cout << "Politness of " << n << " = " << politeness(n) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    PolitenessOfNumber bc;
    bc.input_fun();
return 0;
}

