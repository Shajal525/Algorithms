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
#define INF 10000

struct pii{
    int x,y;
    pii(int a, int b){
        x=a;
        y=b;
    }
};


class POLYGON{
public:
    void input_fun();
    double distance(pii p1, pii p2);
    int orientation(pii p1, pii p2, pii p3);
    bool doIntersect(pii line1_st, pii line1_en, pii line2_st, pii line2_en);
    bool on_this_line(pii line_st, pii line_end, pii pt);
    bool isInsideOfPolygon(pii p, pii arr[], int n);
    double cost(pii arr[], int i, int j, int k);
    double min_cost_polygon_triangulation(pii arr[], int n);
    double polygonArea(pii arr[], int n);
};

double POLYGON::distance(pii p1, pii p2)
{
    return sqrt((p1.x-p2.x) * (p1.x-p2.x) + (p1.y-p2.y) * (p1.y- p2.y));
}

int POLYGON::orientation(pii p1, pii p2, pii p3)
{
    int val = (p3.x - p2.x) * (p2.y - p1.y) - (p3.y - p2.y) * (p2.x - p1.x);
    if(val == 0)
        return 0;
    return (val > 0) ? 1 : 2;   // 1 if Clockwise, 2 if CounterClockwise
}

bool POLYGON::on_this_line(pii line_st, pii line_end, pii pt)    // If point is on line
{
    if(pt.x <= max(line_st.x, line_end.x) && pt.x >= min(line_st.x, line_end.x) &&
            pt.y <= max(line_st.y, line_end.y) && pt.y >= min(line_st.y, line_end.y)){
        return true;
    }
return false;
}

bool POLYGON::doIntersect(pii line1_st, pii line1_en, pii line2_st, pii line2_en)
{
    int o1 = orientation(line1_st, line1_en, line2_st);
    int o2 = orientation(line1_st, line1_en, line2_en);
    int o3 = orientation(line2_st, line2_en, line1_st);
    int o4 = orientation(line2_st, line2_en, line1_en);

    if(o1 != o2 && o3 != o4)
        return true;

    if(o1 == 0 && on_this_line(line1_st, line1_en, line2_st))
        return true;
    if(o2 == 0 && on_this_line(line1_st, line1_en, line2_en))
        return true;
    if(o3 == 0 && on_this_line(line2_st, line2_en, line1_st))
        return true;
    if(o4 == 0 && on_this_line(line2_st, line2_en, line1_en))
        return true;
return false;
}

bool POLYGON::isInsideOfPolygon(pii p, pii arr[], int n)
{
    if(n < 3)
        return false;
    int count = 0;
    pii extreme(INF, p.y);  // Extreme point on x axis
    int prev = n-1;
    for(int i=0; i<n; i++){
        if(doIntersect(arr[prev], arr[i], p, extreme)){ // Check if the lines intersect
            if(orientation(arr[n], arr[i], p) == 0){    // If orientation is zero
                return on_this_line(arr[n], arr[i], p); // If point lies on line then return true else false
            }

            count++;    // Intersect count++
        }
        prev = i;
    }

    return count & 1;   // If count is odd then the point lies inside the polygon
}

double POLYGON::cost(pii arr[], int i, int j, int k)
{
    return distance(arr[i], arr[j]) + distance(arr[j], arr[k]) + distance(arr[k], arr[i]);
}

double POLYGON::min_cost_polygon_triangulation(pii arr[], int n)
{
    if(n < 3)
        return 0;

    double table[n][n];

    for(int gap=0; gap<n; gap++){
        for(int i=0, j=gap; j < n; j++, i++){
            if(j < i+2)
                table[i][j] = 0.0;
            else{
                table[i][j] = INT_MAX;
                for(int k=i+1; k<j; k++){
                    double val = table[i][k] + table[k][j] + cost(arr, i, j, k);
                    if(table[i][j] > val)
                        table[i][j] = val;
                }
            }
        }
    }
   return table[0][n-1];
}

double POLYGON::polygonArea(pii arr[], int n)
{
    double area = 0;
    int p = n-1;
    for(int i=0; i<n; i++){
        area += arr[p].x * arr[i].y - arr[p].y * arr[i].x;
        p = i;
    }

    return abs(area / 2.0);
}

void POLYGON::input_fun()
{
//    pii arr[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    pii p(5, 5);
//    if(isInsideOfPolygon(p, arr, n))
//        cout << "Intersect" << endl;
//    else
//        cout << "Don't Intersect" << endl;

//    pii arr[] = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    cout << min_cost_polygon_triangulation(arr, n) << endl;

    pii arr[] = {{0, 1}, {2, 3}, {4, 7}};
    int n  = sizeof(arr) / sizeof(arr[0]);
    cout << polygonArea(arr, n) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    POLYGON bc;
    bc.input_fun();
return 0;
}

