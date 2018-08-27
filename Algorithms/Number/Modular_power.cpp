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


class Modular_Power{
public:
    /*
     * This function calculate power of any number with a modulas
     *
     * Time Complexity: O(log EXP).
    */
    void input_fun();
    int modular_pow(int n, int exp, int mod);
};

int Modular_Power::modular_pow(int n, int exp, int mod)
{
    int base = n;
    int result = 1;

    while(exp > 0){

        // If Exponent is odd we multiply this with result
        // This will be true at lease once when exp = 1.
        // here we use he property n^6 = (n^2)3 and n^7 = n * n^6.
        if(exp & 1){
            result = (result * base) % mod;
        }

        exp = exp >> 1; // Divide exp by 2

        base = base * base; // Base square.
    }

    return result;
}

void Modular_Power::input_fun()
{
    int mod = 1000;
    int n = 5;
    int exp = 4;

    cout << n << " to the power " << exp << " modulus " << mod << " = " << modular_pow(n, exp, mod) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Modular_Power bc;
    bc.input_fun();
return 0;
}

