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
#define MAXV 1000

class LIS{
    int DP[MAXV];
public:
    /*
     * Longest increasing subsequence problem
     * Time Complexity: O(N*N).
    */
    void input_fun();
    int lis_util(int array[], int n, int ind);
    void lis(int array[], int n);
    void my_idea(int array[], int n);
};

void LIS::my_idea(int array[], int n)
{
    for(int i=0; i<=n; i++)
        DP[i] = -1;

    for(int i=n-1; i>=0; i--){
        int maxx = 0;
        for(int j=i+1; j<n; j++){
            if(array[i] < array[j] && maxx < DP[j])
                maxx = DP[j];
        }
        DP[i] = 1 + maxx;
    }

    int ans=-1,st_ind;
    for(int i=0; i<n; i++){
        if(DP[i] > ans){
            ans = DP[i];
            st_ind = i;
        }
    }
    cout <<"Longest subsequence length is: " << ans << ", Starts at: " << st_ind << endl;
}

int LIS::lis_util(int array[], int n, int ind)
{
    if(ind == n-1)
        return 1;
    if(DP[ind] != -1)
        return DP[ind];
    int maxx = 0;
    for(int i=ind+1; i<n; i++){
        if(array[i] > array[ind]){
            int tmp = lis_util(array, n, i);
            if(tmp > maxx)
                maxx = tmp;
        }
    }
    DP[ind] = 1 + maxx;
    return DP[ind];
}

void LIS::lis(int array[], int n)
{
    for(int i=0; i<=n; i++)
        DP[i] = -1;

    int ans=-1;
    int st_ind = -1;
    for(int i=0; i<n; i++){
        int lll = lis_util(array, n, i);
        if(lll > ans){
            ans = lll;
            st_ind = i;
        }
    }

    cout <<"Longest subsequence length is: " << ans << ", Starts at: " << st_ind << endl;
}

void LIS::input_fun()
{
    int array[] = {5, 0, 9, 2, 7, 3, 4};
    int n = sizeof(array)/sizeof(array[0]);

    //lis(array, n);
    my_idea(array, n);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    LIS bc;
    bc.input_fun();
return 0;
}

