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
pair<int, int> referance_point;

class GEOMETRY{
    struct POINT{
        int x;
        int y;
        POINT(int a, int b){
            x = a;
            y = b;
        }

        bool operator<(POINT p1)    // For sorting based on orientation
        {
            int val = GEOMETRY::orientation(POINT(referance_point.first, referance_point.second), *this, p1);

            if(val == 0)    // If colinear then sort based on distance
                return (distance(POINT(referance_point.first, referance_point.second), p1) >=
                        distance(POINT(referance_point.first, referance_point.second), *this)) ? true : false;
            return (val == 2) ? true : false;   // If CounterClockwise then do nothing else swap
        }
    };
public:
    /*
     * This is Convex Hull Graham Scan's Algorithm.
     * Time Complexity O(N * log N).
     * Referance: geeksforgeeks
    */
    void input_fun();
    void swap(POINT &p1, POINT &p2);
    POINT nextToTop(stack<POINT> &st){  // Next to top in stack
        POINT tmp = st.top();
        st.pop();
        POINT tmp2 = st.top();
        st.push(tmp);
        return tmp2;
    }
    static int distance(POINT p1, POINT p2);
    static int orientation(POINT p1, POINT p2, POINT p3);
    void Convex_Hull(POINT points[], int n);
};


void GEOMETRY::swap(POINT &p1, POINT &p2)
{
    POINT tmp = p1;
    p1 = p2;
    p2 = tmp;
}

int GEOMETRY::distance(POINT p1, POINT p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int GEOMETRY::orientation(POINT p1, POINT p2, POINT p3) // Explained in previous file
{
    int val = (p3.x - p2.x) * (p2.y - p1.y) - (p3.y - p2.y) * (p2.x - p1.x);

    if(val == 0)    // Colinear
        return 0;
    return (val > 0) ? 1 : 2;   // Clockwise or CounterClockwise
}

void GEOMETRY::Convex_Hull(POINT points[], int n)
{
    int miny = 0;
    for(int i=1; i<n; i++){     // Find the bottom left point
        if(points[miny].y > points[i].y)
            miny = i;

        if(points[miny].y == points[i].y)
            miny = (points[miny].x > points[i].x) ? i : miny;
    }
    swap(points[miny], points[0]);  // Make that point first point
    referance_point.first = points[0].x;    // Initialliz referance point with found minimum point
    referance_point.second = points[0].y;

    sort(points+1, points+n);   // Sort all points

    stack<POINT> hull;

    int m=1;
    for(int i=1; i<n; i++){ // If two or more points are colinear with referance point take farthest one only
        while(i < n-1 && orientation(POINT(referance_point.first, referance_point.second), points[i], points[i+1]) == 0)
            i++;
        points[m++] = points[i];
    }

    if(m < 3)
        return;

    hull.push(points[0]);   // Take first three points
    hull.push(points[1]);
    hull.push(points[2]);
    for(int i=3; i<m; i++){
        while(orientation(nextToTop(hull), hull.top(), points[i]) != 2) // If not CounterClockwise then pop.
            hull.pop();

        hull.push(points[i]);
    }

    while(!hull.empty()){
        cout << hull.top().x << " " << hull.top().y << endl;
        hull.pop();
    }
}

void GEOMETRY::input_fun()
{
    POINT points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};

    int n = sizeof(points) / sizeof(points[0]);

    Convex_Hull(points, n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    GEOMETRY bc;
    bc.input_fun();
return 0;
}

