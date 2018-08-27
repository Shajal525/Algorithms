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
struct POINT{
    int x,y;
    POINT(){
        POINT(0,0);
    }
    POINT(int a, int b){
        x = a;
        y = b;
    }
};


class CircumCenter{
public:
    void input_fun();
    void find_circumcenter(POINT P1, POINT P2, POINT P3);
    void equation_for_perpendicular_bisector(POINT P1, POINT P2, int &a, int &b, int &c);
    void equation_from_pints(POINT P1, POINT P2, int &a, int &b, int &c);
    POINT intersection_point(int a1, int b1, int c1, int a2, int b2, int c2);
};

POINT CircumCenter::intersection_point(int a1, int b1, int c1, int a2, int b2, int c2)  // Intersection point of two line
{
    // Only using formula
    double determinant = a1 * b2 - a2 * b1;
    if(determinant == 0)
        return POINT(INT_MAX, INT_MAX);
    else{
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return POINT(x, y);
    }
}

void CircumCenter::equation_from_pints(POINT P1, POINT P2, int &a, int &b, int &c)  // Make equation from two endpoint
{                                                                                   // as "ax + by = c". Calculate a,b and c
    a = P2.y - P1.y;
    b = P1.x - P2.x;
    c = a * P1.x + b * P2.x;
}

void CircumCenter::equation_for_perpendicular_bisector(POINT P1, POINT P2, int &a, int &b, int &c)
{
    // Perpendicular Bisector equation as " ax + by = c". Calculate a,b and c.
    POINT mid_point((P1.x+P2.x)/2, (P1.y+P2.y)/2);

    // Using formula only
    c = -b * mid_point.x + a * mid_point.y;

    int tmp = a;
    a = -b;
    b = tmp;
}

void CircumCenter::find_circumcenter(POINT P1, POINT P2, POINT P3)
{
    int a1, b1, c1;
    equation_from_pints(P1, P2, a1, b1, c1);    // Make equation from any two point
    int a2, b2, c2;
    equation_from_pints(P2, P3, a2, b2, c2);    // Another equation

    equation_for_perpendicular_bisector(P1, P2, a1, b1, c1);    // Find equation for perpendicular bisctor
    equation_for_perpendicular_bisector(P2, P3, a2, b2, c2);    // for both equation.

    POINT circum_center = intersection_point(a1, b1, c1, a2, b2, c2);   // Now calculate intersection point

    cout << "Circumcenter is(x, y): (" << circum_center.x << ", " << circum_center.y << ")" << endl;
return;
}

void CircumCenter::input_fun()
{
    POINT p1(6, 0);
    POINT p2(0, 0);
    POINT p3(0, 8);

    find_circumcenter(p1, p2, p3);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    CircumCenter bc;
    bc.input_fun();
return 0;
}

