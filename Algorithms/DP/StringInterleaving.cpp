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


class INTERLEAVING{
public:
    /*
     * We are given two string of length l1 and l2. Another string of length l=(l1+l2).
     * We need to find if in last string both the two string exists as subsequence.
     * Time Complexity: O(N^2).
     * Referance: Tushar
    */

    bool interleaving_string(string st1, string st2, string str);
    void input_fun();
};

bool INTERLEAVING::interleaving_string(string st1, string st2, string str)
{
    int l1 = st1.length();
    int l2 = st2.length();

    bool dp[l1+1][l2+1];
    memset(dp, 0, sizeof(dp));  // Set as false

    dp[0][0] = true;

    for(int i=0; i<l1; i++){    // When considering only st1
        if(st1[i] == str[i])    // If match then true
            dp[i+1][0] = true;
    }
    for(int i=0; i<l2; i++){    // When considering only st2
        if(st2[i] == str[i])
            dp[0][i+1] = true;
    }

    for(int i=0; i<l1; i++){
        for(int j=0; j<l2; j++){

            int ind = (i+1) + (j+1) - 1;    // Total length of st1 and st2 here

            if(st1[i] == str[ind] && dp[i][j+1] == true)    // If match with st1 then we check top position
                dp[i+1][j+1] = true;
            if(st2[j] == str[ind] && dp[i+1][j] == true)    // If match with st2 then we check left position
                dp[i+1][j+1] = true;
        }
    }
    return dp[l1][l2];
}

void INTERLEAVING::input_fun()
{
    string st1 = "aab";
    string st2 = "axy";
    string str = "aaxaby";  // Result true for this
    //string str = "abaaxy";  // False for this

    bool res = interleaving_string(st1, st2, str);

    cout << "Result is: " << res << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    INTERLEAVING bc;
    bc.input_fun();
return 0;
}

