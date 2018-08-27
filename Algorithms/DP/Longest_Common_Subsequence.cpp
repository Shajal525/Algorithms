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
#define MAXV 1007

class LCS{
    int DP[MAXV][MAXV];
    string st1,st2;
public:
    /*
     * Longest Common Subsequence algorithm.
     * Time complexity: O(N * M). Here N = length of first string and M = length of second string.
     * Longest common Substring can be found with same process.
    */
    void input_fun();
    void initializ();
    int lcs(int i, int j);
    int lcs_iterative(int l1, int l2);
    void printLCS();
};

void LCS::initializ()
{
    for(int i=0; i<MAXV; i++)
        for(int j=0; j<MAXV; j++)
            DP[i][j] = -1;
}

void LCS::printLCS()
{
    int i = st1.length();
    int j = st2.length();
    stack<char> ans;

    while(i > 0 && j > 0){

        if(st1[i-1] == st2[j-1]){
           ans.push(st1[i-1]);
           --i,--j;
        }
        else{
            if(DP[i-1][j] > DP[i][j-1])
                --i;
            else
                --j;
        }
    }
    cout << " The Subsequence is : ";
    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
    cout << endl;
}

int LCS::lcs_iterative(int l1, int l2)
{
    for(int i=0; i<=l1; i++){
        for(int j=0; j<=l2; j++){
            if(i==0 || j==0)
                DP[i][j] = 0;
            else if(st1[i-1] == st2[j-1])
                DP[i][j] = 1 + DP[i-1][j-1];
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]); // If we put DP[i][j]=0 then we will get Longest Common Substring.
        }
    }
    return DP[l1][l2];
}

int LCS::lcs(int i, int j)
{
    if(i == 0 || j == 0)
        return 0;
    if(DP[i][j] != -1)
        return DP[i][j];
    int s = 0;
    if(st1[i-1] == st2[j-1])
        s = 1 + lcs(i-1, j-1);
    else
        s = max(lcs(i, j-1), lcs(i-1, j));  // For Longest Common Substring we need to call the functions but put s=0.
    return DP[i][j] = s;
}

void LCS::input_fun()
{
    initializ();
    cin >> st1 >> st2;

    //int ans = lcs(st1.length(), st2.length());
    int ans = lcs_iterative(st1.length(), st2.length());

    cout << "Length of Longest Common Subsequence of " << st1 << " and " << st2 << " is: " << ans << endl;
    printLCS();
}


int main()
{
    freopen("/home/shajal/Desktop/input.txt", "r+", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    LCS bc;
    bc.input_fun();
return 0;
}

