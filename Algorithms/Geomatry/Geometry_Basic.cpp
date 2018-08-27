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
#define PI 3.1415926535897932384626
#define MAX_VAL 30000
//int SET(int n,int i) {return (n|(1<<i));}
//int RESET(int n,int i) {return (n&~(1<<i));}
//bool check(int n,int i) {return (n&(1<<i));}
using namespace std;

//Template Ends Here

struct POINT{
    int x;
    int y;
    POINT(){
        POINT(0, 0);
    }
    POINT(int x, int y){
        this->x = x;
        this->y = y;
    }
};
struct D_POINT{
    double x;
    double y;
    D_POINT(){
        POINT(0, 0);
    }
    D_POINT(double x, double y){
        this->x = x;
        this->y = y;
    }
};

class GEOMETRY{
public:
    /*
     * This is basic of geometry. Here we demonstrate orientation.
     * Using orientation we can check if 2 line intersect or not.
    */
    void input_fun();
    int gcd(int a, int b);
    int orientation(POINT p1, POINT p2, POINT p3);
    bool check_If_Intersect_With_Each_Other(POINT l1_st, POINT l1_end, POINT l2_st, POINT l2_end);
    bool on_this_line(POINT line_st, POINT line_end, POINT pt);
    int num_of_integral_points_on_line(POINT p1, POINT p2);
    int num_of_integral_points_inside_triangle(POINT p1, POINT p2, POINT p3);
    D_POINT rotation_of_point_about_origin(D_POINT p, double theta);
    D_POINT rotation_of_point_about_another_point(D_POINT p, D_POINT about_this_point, double theta);
};

int GEOMETRY::gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int GEOMETRY::num_of_integral_points_on_line(POINT p1, POINT p2)    // Integral points over a line
{
    if(p1.x == p2.x)    // If parallel to x axis
        return abs(p2.y - p1.y) - 1;
    if(p1.y == p2.y)    // If parallel to y axis
        return abs(p2.x - p1.x) - 1;

    return gcd(abs(p2.x - p1.x), abs(p2.y - p1.y)) - 1;
}

int GEOMETRY::num_of_integral_points_inside_triangle(POINT p1, POINT p2, POINT p3)
{
    // This algorithm also works for polygons.
    // All points over lines
    int num_of_point_over_lines = num_of_integral_points_on_line(p1, p2) + num_of_integral_points_on_line(p1, p3) +
            num_of_integral_points_on_line(p2, p3) + 3;

    // Area of this triangle
    int area = abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2;

    // This is formula for calculating points inside triangle
    return area - (num_of_point_over_lines / 2) + 1;
}

bool GEOMETRY::on_this_line(POINT line_st, POINT line_end, POINT pt)    // If point is on line
{
    if(pt.x <= max(line_st.x, line_end.x) && pt.x >= min(line_st.x, line_end.x) &&
            pt.y <= max(line_st.y, line_end.y) && pt.y >= min(line_st.y, line_end.y)){
        return true;
    }
return false;
}

int GEOMETRY::orientation(POINT p1, POINT p2, POINT p3)
{
    /*
     * This is very very importent. There is three orientation
     * 1. Colinear
     * 2. Clockwise
     * 3. CounterClockwise
     *
     * We need to find slope of p1 and p2 then slope of p2 and p3.
     * If slope of p1 and p2 is X then X = (p2.y - p1.y) / (p2.x - p1.x)
     * If slope of p2 and p3 is Y then Y = (p3.y - p2.y) / (p3.x - p2.x)
     * Now from this we can take val = Y - X. Normalized formula given below.
     * Referance: geeksforgeeks.com
    */
    int val = (p3.x - p2.x) * (p2.y - p1.y) - (p3.y - p2.y) * (p2.x - p1.x);

    if(val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

bool GEOMETRY::check_If_Intersect_With_Each_Other(POINT l1_st, POINT l1_end, POINT l2_st, POINT l2_end)
{
    int ori1 = orientation(l1_st, l1_end, l2_st);   // Check all orientation
    int ori2 = orientation(l1_st, l1_end, l2_end);
    int ori3 = orientation(l2_st, l2_end, l1_st);
    int ori4 = orientation(l2_st, l2_end, l1_end);

    if(ori1 != ori2 && ori3 != ori4)    // If both orientation are diffrent then they surely intersect.
        return true;

    if(ori1 == 0 && on_this_line(l1_st, l1_end, l2_st)) // If those three points are colinear and thard point is on this line
        return true;
    if(ori2 == 0 && on_this_line(l1_st, l1_end, l2_end))
        return true;
    if(ori3 == 0 && on_this_line(l2_st, l2_end, l1_st))
        return true;
    if(ori4 == 0 && on_this_line(l2_st, l2_end, l1_end))
        return true;

    return false;
}

D_POINT GEOMETRY::rotation_of_point_about_origin(D_POINT p, double theta)
{
    D_POINT after_rotation;
    double si = sin(theta);
    double co = cos(theta);

    after_rotation.x = p.x * co - p.y * si;     // This is formula. I can proof this formula
    after_rotation.y = p.x * si + p.y * co;
    return after_rotation;
}

D_POINT GEOMETRY::rotation_of_point_about_another_point(D_POINT p, D_POINT about_this_point, double theta)
{
    p.x -= about_this_point.x;     // We need to translate points to origin
    p.y -= about_this_point.y;

    p = rotation_of_point_about_origin(p, theta);   // Now normaly rotate about origin

    p.x += about_this_point.x;  // Add the value which we subtracted
    p.y += about_this_point.y;

    return p;
}

void GEOMETRY::input_fun()
{
//    POINT l1_start(0, 0);
//    POINT l1_end(5, 0);
//    POINT l2_start(0, 5);
//    POINT l2_end(10, 10);

//    cout << "Number inside Triangle: " << num_of_integral_points_inside_triangle(l1_start, l1_end, l2_start) << endl;
    //bool ans = check_If_Intersect_With_Each_Other(l1_start, l1_end, l2_start, l2_end);

    //if(ans)
     //   cout << "Intersect with each other" << endl;
   // else
       // cout << "Not Intersect with each other" << endl;
    D_POINT p(4.0, 3.0);
    D_POINT q(2.0, 2.0);
    p = rotation_of_point_about_another_point(p, q, PI/2);

    cout << p.x << " " << p.y << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    GEOMETRY bc;
    bc.input_fun();
return 0;
}

