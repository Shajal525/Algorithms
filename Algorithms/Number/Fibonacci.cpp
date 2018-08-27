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


class Fibonacci{
public:
    /*
     * Both DP recursive and iterative Fibonacci function takes O(N) time.
     * Space Complexity: O(N).
     * We can do that in O(1) space complexity, but then we can't save previous fibonacci
     * umbers in fibo[] array.
    */
    ll fibonacci_rec(ll fibo[], int i);
    void fibonacci_ite(ll fibo[], int n);
    /*
     * We can calculate Fibonacci using matrix multilication.
     *
     * F(n+1), F(n)     =   {1, 1
     * F(n)  , F(n-1)        1, 0} ^n
     *
     * So, if we multiply mat[][]={{1,1},{1,0}} matrix N time we will get N'th Fibonacci number.
     * Time Complexity: O(N) But if we optimize the Power() function then we can
     * do this in O(log N) time.
     * So, Time Complexity: O(log N);
     * Space Comlexity: O(1).
     *
     * This algorithm is useful only if we need single fibonacci number.
     * If we need multiple fibonacci numbers then the method below this is best.
    */
    ll fibonacci_mat(int n);
    void multiply(ll F[2][2], ll M[2][2]);
    void power(ll F[2][2], int n);
    void optimized_Power(ll F[2][2], int n);
    /*
     * We can calculate and build a recursieve relation from the matrix
     *
     * F(n+1), F(n)     =   {1, 1
     * F(n)  , F(n-1)        1, 0} ^n ;
     *
     * We will get,
     * If n is even then k = n/2:
     * F(n) = [2*F(k-1) + F(k)]*F(k)
     *
     * If n is odd then k = (n + 1)/2
     * F(n) = F(k)*F(k) + F(k-1)*F(k-1)
     *
     * Prove of this here: https://en.wikipedia.org/wiki/Fibonacci_number#Matrix_form.
     * Time complexity: O(log N).
     * Space Complexity: O(N) as we can save values here. If we don't
     * save then space complexity will be O(1).
     * This is best algorithm for Fibonacci in all situation.
    */
    ll fibonacciRecersiveLogN(ll fib[], int i);
    /*
     * There is an easy way to check if a number is Fibonacci number or not.
     * A number n is Fibonacci if and only if one or both of (5*n2 + 4) or (5*n2 – 4) is a perfect square
    */
    bool isPerfectSquare(int n);
    bool isFibonacci(int n);
    void input_fun();
    /*
     * Facts about Fibonacci numbers..
     *
     * 1. Last digit of fibonacci numbers:
     *  Look at the final digit in each Fibonacci number – the units digit:
     *  0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, ...
     *
     *  Is there a pattern in the final digits?
     *  0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, ...
     *  Yes! This sequence is also fibonacci modulo 10!!!
     *  Also this pattern repeats after 60 numbers.
     *
     * 2.
     *  Every 3-rd Fibonacci number is a multiple of 2
     *  Every 4-th Fibonacci number is a multiple of 3
     *  Every 5-th Fibonacci number is a multiple of 5
     *  Every 6-th Fibonacci number is a multiple of 8
     *
     * 3.
     *  We have some Fibonacci
     *  number like F(1) = 1 which is divisible by 1, F(5) = 5 which is divisible
     *  by 5, F(12) = 144 which is divisible by 12, F(24) = 46368 which is divisible
     *  by 24, F(25) = 75025 which is divisible by 25. This type of index number
     *  follow a certain pattern. First, let’s keep a look on those index number :
     *  1, 5, 12, 24, 25, 36, 48, 60, 72, 84, 96, 108, 120, 125, 132, …..
     *  On observing it, this series is made up of every number that is multiple
     *  of 12 as well as all the number that satisfies the condition
     *  of pow(5, k), where k = 0, 1, 2, 3, 4, 5, 6, 7, ……
     *
     * 4.
     *  Value of f(n-1)*f(n+1) – f(n)*f(n) is (-1)n.
     *
     * Extra:
     *  Every number can be represented as a sum of non neighbouring Fibonacci numbers.
     *  Input:  n = 10
     *  Output: 8 2
     *
     *  Input:  n = 30
     *  Output: 21 8 1
     *
     *  We can solve this using greedy approach.
     *  We will take nearest Fibonacci number less then N, Then print that number and
     *  make N=(N-fibonacci). Now repeat same process for new value of N until N becomes 0.
     *
    */

};

ll Fibonacci::fibonacci_rec(ll fibo[], int i)
{
    if(fibo[i] != -1)
        return fibo[i];
    if(i == 0)
        return fibo[0]=0;
    if(i == 1)
        return fibo[1]=1;

    return fibo[i] = fibonacci_rec(fibo, i-1) + fibonacci_rec(fibo, i-2);
}

void Fibonacci::fibonacci_ite(ll fibo[], int n)
{
    fibo[0] = 0;
    fibo[1] = 1;

    for(int i=2; i<n; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
}

ll Fibonacci::fibonacci_mat(int n)
{
  ll F[2][2] = {{1,1},{1,0}};
  if (n == 0)
      return 0;
  //power(F, n-1);    // for power n, F[0][0] will always return n+1'th fibonacci number.
                    // So, for n-1 it will return N't fibonacci number.
  optimized_Power(F, n-1);

  return F[0][0];
}

void Fibonacci::multiply(ll F[2][2], ll M[2][2])
{
  ll x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  ll y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  ll z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  ll w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void Fibonacci::power(ll F[2][2], int n)
{
  int i;
  ll M[2][2] = {{1,1},{1,0}};

  // n - 1 times multiply the matrix to {{1,0},{0,1}}
  for (i = 2; i <= n; i++)
      multiply(F, M);
}

void Fibonacci::optimized_Power(ll F[2][2], int n)
{
    // This is recurseve.
//    if(n == 1)
//        return;
//    ll M[2][2] = {{1, 1}, {1, 0}};

//    optimized_Power(F, n/2);
//    multiply(F, F);

//    if(n & 1){
//        multiply(F, M);
//    }

    // This is iterative implementation.

    // This is initializ like this because this is like 1 for variable.
    // When we will multiply any matrix with this matrix we will get that ,atrix as result.
    ll M[2][2] = {{1, 0}, {0, 1}};

    // M^17 can be written as ((M^2)^8) * M. Here power is odd.
    // M^16 can be written as ((M^2)^8. Here power is even.
    // We will save all values when we get any odd power. At last we will multiply M with F.
    while(n > 1){

        if(n & 1){
            multiply(M, F);
        }
        multiply(F, F);
        n /= 2;
    }
    multiply(F, M);
}

// Best Fibonacci number finding algorithm...
// Time complexity: O(log N)..
ll Fibonacci::fibonacciRecersiveLogN(ll fib[], int i)
{
    if(fib[i] != -1)
        return fib[i];
    if(i == 0)
        return fib[0]=0;
    if(i == 1)
        return fib[1]=1;

    int k = (i & 1) ? (i+1)/2 : i/2;

    ll fib_k = fibonacciRecersiveLogN(fib, k);
    ll fib_k_1 = fibonacciRecersiveLogN(fib, k-1);

    if(i & 1){
        // If power is odd, Use this formula..
        fib[i] = fib_k*fib_k + fib_k_1*fib_k_1;
    }
    else{
        // If power is even, Use this formula.
        fib[i] = fib_k*fib_k + 2 * fib_k * fib_k_1;
    }
    return fib[i];
}

bool Fibonacci::isPerfectSquare(int n)
{
    int sq = sqrt(n);
    return (sq*sq == n) ? 1 : 0;
}

bool Fibonacci::isFibonacci(int n)
{
    return isPerfectSquare(5*n*n+4) || isPerfectSquare(5*n*n-4);
}

void Fibonacci::input_fun()
{
    ll fibo[1009];
    for(int i=0; i<1005; i++)
        fibo[i] = -1;

    cout << fibonacci_rec(fibo, 70) << endl;


    fibonacci_ite(fibo, 1005);
    cout << fibo[70] << endl;


    cout<< fibonacci_mat(70) << endl;



    fibonacciRecersiveLogN(fibo, 1005);
    cout << fibo[70] << endl;

    for (int i = 1; i <= 10; i++)
         isFibonacci(i)? cout << i << " is a Fibonacci Number \n":
                         cout << i << " is a not Fibonacci Number \n" ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Fibonacci bc;
    bc.input_fun();
return 0;
}

