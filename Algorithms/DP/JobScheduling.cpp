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

struct Node{
    int st_time,en_time;
    int profit;
    Node(int st, int en, int p):st_time(st),en_time(en),profit(p){}

    bool operator<(const Node nn){
        return this->en_time < nn.en_time;  // Will sort according to end time.
    }
};

class JobScheduling{
public:
    /*
     * This is Job Scheduling Problem.
     * We are given number of job and there starting and ending time and profit we can make form each job.
     * We need to find maximum profit that we can make. No job can overlap.
     * Time Complexity: O(N*N).
    */
    int job_schedul(vector<Node> vt);
    void input_fun();
};

int JobScheduling::job_schedul(vector<Node> vt)
{
    int l = vt.size();
    sort(vt.begin(), vt.end()); // First sort all jobs according to there end time.
    int array[l];

    for(int i=0; i<l; i++)
        array[i] = vt[i].profit;    // Initially array contains profit each job can make

    for(int i=1; i<l; i++){
        for(int j=0; j<i; j++){ // From 0 to i-1

            if(vt[j].en_time <= vt[i].st_time)  // If two job dose not overlap then
                array[i] = max(array[i], array[j] + vt[i].profit);
        }
    }

    int mx = -1;
    for(int i=0; i<l; i++)  // Go through all element of array and find max
        if(array[i] > mx)
            mx = array[i];

    return mx;
}

void JobScheduling::input_fun()
{
    vector<Node> vt;
    vt.push_back(Node(1, 3, 5));
    vt.push_back(Node(2, 5, 6));
    vt.push_back(Node(4, 6, 5));
    vt.push_back(Node(6, 7, 4));
    vt.push_back(Node(5, 8, 11));
    vt.push_back(Node(7, 9, 2));

    int ans = job_schedul(vt);
    cout << ans << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    JobScheduling bc;
    bc.input_fun();
return 0;
}

