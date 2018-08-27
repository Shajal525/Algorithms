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


class Divisors{
public:
    /*
     * Time Complexity: O(sqrt(n)).
     *
     *
     * In efficient algorithm Time Complexity is in between O(log N) to O(sqrt(N)).
    */
    void print_All_Divisors(int n);
    void sum_of_all_divisors_efficient(int n);
    /*
     * This is an efficient algorithm for calculating All Pirme Factors of Number when we have multiple quary.
     * This algorithm use Sieve to calculate lowest prime factor of each number.
     * This preprocessing takes O(N*log log N) time.
     * Each Quary takes O(log N).
     * Space Complexity: O(N).
    */
    void lowestPrimeFactor(int LPF[], int n);
    void allPrimeFactors(int LPF[], int n);
    void input_fun();
    /*
     * When P is prime, sum of 0 to N th power of P is
     * 1 + p^1 + p^2 + p^3 + ...... + p^N = ((p^(n+1)) - 1) / (p-1).
     */

};

// Easy
void Divisors::print_All_Divisors(int n)
{
    for(int i=1; i*i<=n; i++){  // We must use <= here
        if(n % i == 0){

            if(n/i == i){
                cout << i << " ";
            }
            else{
                cout << i << " " << n/i << " ";
            }
        }
    }
}

/*
 * Time Complexity is in between O(log N) to O(sqrt(N)).
Consider the number 18.

Sum of factors = 1 + 2 + 3 + 6 + 9 + 18

Writing divisors as powers of prime factors.
Sum of factors = (2^0)(3^0) + (2^1)(3^0) + (2^0)(3^1) +
                 (2^1)(3^1) + (2^0)(3^2) + (2^1)(3^2)
               = (2^0)(3^0) + (2^0)(3^1) + (2^0)(3^2) +
                 (2^1)(3^0) + (2^1)(3^1) + (2^1)(3^2)
               = (2^0)(3^0 + 3^1 + 3^2) +
                 (2^1)(3^0 + 3^1 + 3^2)
               = (2^0 + 2^1)(3^0 + 3^1 + 3^2).
*/
void Divisors::sum_of_all_divisors_efficient(int n)
{
    int cur_divisor,cur_sum,divisor_sum=1,i=2;

    while(i*i<=n){
        cur_divisor = 1;
        cur_sum = 1;
        while(n%i == 0){
            // Dividing n by i
            // This part makes this algorithm efficient
            n /= i;
            cur_divisor *= i;
            cur_sum += cur_divisor;
        }
        divisor_sum *= cur_sum;
        i++;
    }

    if(n>2)
        divisor_sum *= (n+1);   // Must add 1 with n. Becaus (n^0+n^1)=(1+n)

    cout << "Divisor sum is: " << divisor_sum << endl;
}

// LPF is Lowest prime factor
void Divisors::lowestPrimeFactor(int LPF[], int n)
{
    // Initially every number is substituted as its LPF
    for(int i=1;i<n;i++)
        LPF[i] = i;

    // LPF of all even number is 2
    for(int i=4; i<n; i+=2)
        LPF[i] = 2;

    for(int i=3; i*i<n; i+=2){

        // If the number is prime then LPF[i] = i
        if(LPF[i] == i){

            for(int j=i*i; j<n; j+=i){

                // If number is not visited yet then i is LPF of j
                // Else we already calculated its LPF
                if(LPF[j] == j)
                    LPF[j] = i;
            }
        }
    }

}

void Divisors::allPrimeFactors(int LPF[], int n)
{
    // This process will print same prime factor multiple times.
    // To print each factor only once we can use STL set
    while(n != 1){
        cout << LPF[n] << " ";  // LPF is Smallest prime factor of n
        n /= LPF[n];    // Divide n with its LPF. Now we have new value of N and new LPF for this N
    }
}

void Divisors::input_fun()
{
    int n;
    cin >> n;

    print_All_Divisors(n);
    sum_of_all_divisors_efficient(n);

    int LPF[99999];
    lowestPrimeFactor(LPF, 99999);
    allPrimeFactors(LPF, n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Divisors bc;
    bc.input_fun();
return 0;
}

