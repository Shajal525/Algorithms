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
#define PI 3.1415926535897932384626
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x<y?x:y
#define MAX_VAL 30000
//int SET(int n,int i) {return (n|(1<<i));}
//int RESET(int n,int i) {return (n&~(1<<i));}
//bool check(int n,int i) {return (n&(1<<i));}
using namespace std;

//Template Ends Here

struct POINT{
    int x,y;
};

class CLOSEST_PAIR{
public:
    /*
     * Given some cordinates of points. This algorithm finds Closest Pair of Point among those points.
     * Time Complexity: O(N * log N).
     * There is simplified version of this algorithm which works in O(N * log N * log N).
    */
    void input_fun();
    static int compareX(const void *a, const void *b);
    static int compareY(const void *a, const void *b);
    double distance(POINT p1, POINT p2);
    double brute_force(POINT p_a[], int n);
    double strip_closest(POINT strip[], int siz, double d);
    double closest_util(POINT Px[], POINT Py[], int n);
    double closest(POINT P_a[], int n);
};

int CLOSEST_PAIR::compareX(const void *a, const void *b)    // Compare about X axis
{
    POINT *p1 = (POINT *)a;
    POINT *p2 = (POINT *)b;
    return (p1->x - p2->x);
}

int CLOSEST_PAIR::compareY(const void *a, const void *b)    // Compare about Y axis
{
    POINT *p1 = (POINT *)a;
    POINT *p2 = (POINT *)b;
    return p1->y - p2->y;
}

double CLOSEST_PAIR::distance(POINT p1, POINT p2)
{
    double dis = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    return sqrt(dis);
}

double CLOSEST_PAIR::brute_force(POINT p_a[], int n)    // Brute Force Method of calculating Closest Point
{                                                       // This will take O(N * N) time.
    double min = INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
                double t = distance(p_a[i], p_a[j]);
                min = (min > t) ? t : min;
        }
    }

    return min;
}

double CLOSEST_PAIR::strip_closest(POINT strip[], int siz, double d)
{
    double min = d;
    //qsort(strip, siz, sizeof(POINT), compareY);  // Sort about Y axis. We need this in simplified version of this algo
    for(int i=0; i<siz; i++){                                           // Because strip array is sorted about Y axis
        for(int j=i+1; j<siz && (strip[j].y - strip[i].y) < min; j++){  // This is proved that this loop runs maximum 6 times
            double t = distance(strip[i], strip[j]);
            if(t < min)
                min = t;
        }
    }

    return min;
}

double CLOSEST_PAIR::closest_util(POINT Px[], POINT Py[], int n)
{
    if(n <= 3)                      // If N is less then 3 we brute force
        return brute_force(Px, n);

    int mid = n/2;
    POINT midPoint = Px[mid];   // Mid point of X axis

    POINT Pyl[mid+1];   // We will store all points on left side of mid point in this array
    POINT Pyr[n-mid];   // Here we will store points of right side
    int li=0, ri=0;

    for(int i=0; i<n; i++){
        if(Py[i].x <= midPoint.x)
            Pyl[li++] = Py[i];
        else
            Pyr[ri++] = Py[i];
    }

    double d_l = closest_util(Px, Pyl, mid);    // Divide and conquare. Use Pyl for this
    double d_r = closest_util(Px+mid, Pyr, n-mid);  // Use Pyr for this. Also use Px+mid

    double d = MIN(d_l, d_r);

    POINT strip[n];     // This array is for storing all the points near mid point

    int j=0;
    for(int i=0; i<n; i++)
        if(abs(Py[i].x - midPoint.x) < d)   // If the point is closer then d from mid point we store it
            strip[j++] = Py[i];             // here we use Py so that strip array is sorted about Y axis.

    return min(d, strip_closest(strip, j, d));  // stripe_closest function find Closest Point in strip array
}

double CLOSEST_PAIR::closest(POINT P_a[], int n)
{
    POINT Px[n];
    POINT Py[n];
    for(int i=0; i<n; i++){
        Py[i] = P_a[i];
        Px[i] = P_a[i];
    }

    qsort(Px, n, sizeof(POINT), compareX);  // Sort about X axis
    qsort(Py, n, sizeof(POINT), compareY);  // Sort about Y axis

    return closest_util(Px, Py, n); // We don't need Py in simplified version.
}

void CLOSEST_PAIR::input_fun()
{
    POINT p[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(p) / sizeof(p[0]);

    double ans = closest(p, n);

    cout << "Smallest distance is : " << ans << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    CLOSEST_PAIR bc;
    bc.input_fun();
return 0;
}

