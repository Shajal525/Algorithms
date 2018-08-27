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
#define EPSILON numeric_limits<double>::epsilon()


class MAX_NUM_OF_TRIANGLE{
public:
    /*
     * This algorithm is used to calculate maximum number of triangle  possible from a given set of points.
     * Time Complexity: O(N * log N).
    */
    void input_fun();
    int num_of_triangle(int a[], int b[], int c[], int n);
    bool compareDouble(double a, double b){
        double dif = b - a;
        return dif < EPSILON && -dif < EPSILON;
    }
};

int MAX_NUM_OF_TRIANGLE::num_of_triangle(int a[], int b[], int c[], int n)  // c not needed
{
    double slope[n];
    for(int i=0; i<n; i++)  // Calculate slope for each line
        slope[i] = (a[i]*1.0) / (b[i]*1.0);
    sort(slope, slope+n);   // Sort slops

    int count[n], k=0;
    int cou_this = 1;
    for(int i=1; i<n; i++){     // Count same slope and save in count array
        if(compareDouble(slope[i], slope[i-1])){
            cou_this++;
        }
        else{
            count[k++] = cou_this;
            cou_this = 1;
        }
    }
    count[k++] = cou_this;

    /*
     * This is a very nice formula.
     * This is used to calculate sum = m1*m2*m3 + m1*m2*m4 + m1*m3*m4 + m2*m3*m4. This is for 4 numbers.
     * This also works for more numbers. The idea is to calculate
     * sum1 = m1 + m2 + m3 + m4 + ....
     * sum2 = m1*m2 + m1*m3 + m1*m4 + m2*m3 + m2*m4 + m3*m4 + .....
     * sum3 = m1*m2*m3 + m1*m2*m4 + m1*m3*m4 + m2*m3*m4 + ....
    */
    int sum1 = 0;
    for(int i=0; i<k; i++)
        sum1 += count[i];

    int sum2 = 0;
    int tmp[k];
    for(int i=0; i<k; i++){
        tmp[i] = count[i] * (sum1 - count[i]);  // Subtract i'th count then multiply
        sum2 += tmp[i];
    }
    sum2 = sum2 / 2;    // Each valu counted twice. So divide by 2

    int sum3 = 0;
    for(int i=0; i<k; i++)
        sum3 += count[i] * (sum2 - tmp[i]); // Again discard all i'th tmp then multiply

    sum3 = sum3 / 3;    // This time each value calculated thrice. So divide by 3

    return sum3;    // This is the ans
}

void MAX_NUM_OF_TRIANGLE::input_fun()
{
    // a,b and c value for four straight lines as "ax + by = c"
    int a[] = {1, 2, 3, 4};
    int b[] = {2, 4, 5, 5};
    int c[] = {5, 7, 8, 6};

    int n = sizeof(a) / sizeof(a[0]);

    int ans = num_of_triangle(a, b, c, n);

    cout << "Maximum number of triangle possible from given poin is: " << ans << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    MAX_NUM_OF_TRIANGLE bc;
    bc.input_fun();
return 0;
}

