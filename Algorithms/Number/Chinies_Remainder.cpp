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


class Chinies_Remainder{
public:
    /*
     * Chinies Remainder Theorem:
     * We are given two arrays num[0..k-1] and rem[0..k-1]. In num[0..k-1],
     * every pair is coprime. We need to find minimum positive number x such that:
     *      x % num[0]    =  rem[0],
     *      x % num[1]    =  rem[1],
     *      .......................
     *      x % num[k-1]  =  rem[k-1] .
     *
     * Example:
     *  nput:  num[] = {3, 4, 5}, rem[] = {2, 3, 1}
     *  Output: 11
     *  Explanation:
     *      11 is the smallest number such that:
     *      (1) When we divide it by 3, we get remainder 2.
     *      (2) When we divide it by 4, we get remainder 3.
     *      (3) When we divide it by 5, we get remainder 1.
     *
     * The efficient way to do this is given below:
     *  rem[i] is given array of remainders.
     *
     *  prod is product of all given numbers
     *  prod = num[0] * num[1] * ... * num[k-1]
     *
     *  pp[i] is product of all divided by num[i]
     *  pp[i] = prod / num[i]
     *
     *  inv[i] = Modular Multiplicative Inverse of
     *        pp[i] with respect to num[i]
     *
     *  Let us take below example to understand the solution
     *      num[] = {3, 4, 5}, rem[] = {2, 3, 1}
     *      prod  = 60
     *      pp[]  = {20, 15, 12}
     *      inv[] = {2,  3,  3}  // (20*2)%3 = 1, (15*3)%4 = 1
     *                         // (12*3)%5 = 1
     *
     *      x = (rem[0]*pp[0]*inv[0] + rem[1]*pp[1]*inv[1] +
     *         rem[2]*pp[2]*inv[2]) % prod
     *      = (2*20*2 + 3*15*3 + 1*12*3) % 60
     *      = (40 + 135 + 36) % 60
     *      = 11
     *
     * Time Complexity: O(N log N).
     *
    */
    int mudular_Inverse(int a, int m);
    int chinies_RT_effi(int num[], int rem[], int k);
    void input_fun();
};

// Returns modulo inverse of a with respect to m using extended
// Euclid Algorithm. Refer below post for details:
int Chinies_Remainder::mudular_Inverse(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
       return 0;

    // Apply extended Euclid Algorithm
    while (a > 1)
    {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
       x1 += m0;

    return x1;
}

int Chinies_Remainder::chinies_RT_effi(int num[], int rem[], int k)
{
    // Calculate product of all num.
    int product = 1;
    for(int i=0; i<k; i++)
        product *= num[i];

    int result = 0;
    for(int i=0; i<k; i++){
        // For formula
        int pp = product/num[i];

        int inv = mudular_Inverse(pp, num[i]);
        result += (pp * inv * rem[i]);      // This is implementation of the above formula.
    }
    return result % product;    // Must take modulas.
}

void Chinies_Remainder::input_fun()
{
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    int k = sizeof(num)/sizeof(num[0]);
    cout << "x is " << chinies_RT_effi(num, rem, k) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Chinies_Remainder bc;
    bc.input_fun();
return 0;
}

