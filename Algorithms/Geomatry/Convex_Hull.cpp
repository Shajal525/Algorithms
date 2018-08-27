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

class GEOMETRY{
public:
    /*
     * This is Convex Hull Jarvis's Algorithm.
     * Time Complexity O(N * N).
     * Referance: geeksforgeeks
    */
    void input_fun();
    int orientation(POINT p1, POINT p2, POINT p3);
    void Convex_Hull(POINT points[], int n);
};

int GEOMETRY::orientation(POINT p1, POINT p2, POINT p3) // Explained in previous file
{
    int val = (p3.x - p2.x) * (p2.y - p1.y) - (p3.y - p2.y) * (p2.x - p1.x);

    if(val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

void GEOMETRY::Convex_Hull(POINT points[], int n)
{
    vector<POINT> hull;

    int minx = 0;
    for(int i=1; i<n; i++)                  // Find bottom point. That means minimum x
        if(points[minx].x > points[i].x)
            minx = i;

    int p = minx, q;
    do{
        hull.push_back(points[p]);  // Push p to convex hull

        q = (p+1) % n;      // Take a random point q
        for(int i=0; i<n; i++){     // For each point compare it with q and take it as q if those condition satisfied
            if(orientation(points[p], points[q], points[i]) == 1)   // Or Use if(orientation(points[p],points[i],points[q])==2)
                q = i;
        }
        p = q;          // Update p
    }while(minx != p);

    for(int i=0; i<(int)hull.size(); i++)
        cout << hull[i].x << " " << hull[i].y << endl;
}

void GEOMETRY::input_fun()
{
    POINT points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};

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

