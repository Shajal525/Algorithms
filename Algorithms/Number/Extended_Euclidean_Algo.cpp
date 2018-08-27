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


class ExtendedEuclidean{
public:

    void input_fun();
    /*
     * Euclidian algorithm is used to find GCD.
     * Extended Euclidean algorithm also finds integer coefficients x and y such that:
     * ax + by = gcd(a, b).
     * Here x and y is coefficient. Extended Euclidean algorithm finds them.
     * Ex: Input: a = 30, b = 20
     * Output: gcd = 10
     * x = 1, y = -1
     * (Note that 30*1 + 20*(-1) = 10)
     *
     * Time Complexty is same as Eucilidean: O(log min(a,b)).
     */

    int GCDwithCoefficient(int a, int b, int &x, int &y);
};

int ExtendedEuclidean::GCDwithCoefficient(int a, int b, int &x, int &y)
{
    // Those are normal gcd trick.
    if(a == 0){
        x = 0;
        y = 1;
        return  b;
    }
    int x1,y1;

    int gcd = GCDwithCoefficient(b%a, a, x1, y1);

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

void ExtendedEuclidean::input_fun()
{
    int x,y,a,b;
    cin >> a >> b;

    int gcd = GCDwithCoefficient(a, b, x, y);

    cout << "GCD of " << a << " and " << b << " is: " << gcd << endl;
    cout << "Coefficients are : " << x << " and "<< y << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ExtendedEuclidean bc;
    bc.input_fun();
return 0;
}

