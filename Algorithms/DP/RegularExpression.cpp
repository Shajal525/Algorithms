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


class Expression{
public:
    /*
     * We are given a string and a patern. Patern can have '*' and '.'
     * Here '.' means any single charecter and '*' means zero or more occurance of previous charecter of '*'
     * Time complexity: O(N*M) Where M=string length and N=pattern length
     * Space Complexity: O(N*M).
    */
    bool expression_match(string str, string patern);
    void input_fun();
};

bool Expression::expression_match(string str, string patern)
{
    int len1 = str.length();
    int len2 = patern.length();

    // String is row and patern is column
    int dp[len1+2][len2+2];
    dp[0][0] = true;    // If both patern and string is of length zero

    for(int i=1; i<=len1; i++)
        dp[i][0] = false;   // If patern is of length zero then for any string its not a match

    for(int i=1; i<=len2; i++){
        if(patern[i-1] == '*'){     // If string is zero and patern is '*' we check if zero occurance is a match or not.
            dp[0][i] = dp[0][i-2];
            continue;
        }
        dp[0][i] = false;
    }

    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){

            if(patern[j-1] == '*'){ // If its a '*'
                // Here We check 2 steps back for checking if zero occurance is a match or not
                if(dp[i][j-2] == true)
                    dp[i][j] = true;
                // Here we chesk if charecter of the string matches previous charecter of '*' or it's a '.'
                // and top dp array is true. That is for any occurances of charecter.
                else if((patern[j-2] == str[i-1] || patern[j-2] == '.') && dp[i-1][j] == true)
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            else if(patern[j-1] == '.' || patern[j-1] == str[i-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = false;
        }
    }

    return dp[len1][len2];
}

void Expression::input_fun()
{
    string str = "xmmmmblc";
    string pat = "x.*b.c";

    bool ans = expression_match(str, pat);

    if(ans)
        cout << "This string matches the patern" << endl;
    else
        cout << "This string don't match the patern" << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Expression bc;
    bc.input_fun();
return 0;
}

