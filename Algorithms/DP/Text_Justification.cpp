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

#define inf 99999999

class JUSTIFICATION{
public:
    /*
     * We are given some strings. We need to justify the strings in a page of width 10
     * such that space left at the end of each line is minimum.
     * We justify by calculating the sum of square of space left in each line.
     * Time complexity: O(N^2).
     * Space Complexity: O(N^2).
     * Ref.: Tusher
    */
    void print_stringPath(string st[], int path[], int n);
    int text_justify(string st[], int n, int page_width);
    void input_fun();
};

void JUSTIFICATION::print_stringPath(string st[], int path[], int n)
{
    int i=0;
    while(i != n){  // While not end of word

        int tmp = path[i];  // i'th word to (path[i]-1)'th word will be in same line

        while(i != tmp){  // Print all word in this line
            cout << st[i++] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

int JUSTIFICATION::text_justify(string st[], int n, int page_width)
{
    int dp[n][n];
    int cumulative_length[n];
    cumulative_length[0] = 0;   // Here i will store cumulative length of each word
    for(int i=0; i<=n; i++)
        cumulative_length[i+1] = cumulative_length[i] + st[i].length(); // Storing cumulative length

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            // If we are checking for one word then cost is square of page width - length of that word
            if(i == j)
                dp[i][i] = pow(page_width - (cumulative_length[i+1] - cumulative_length[i]), 2);
            // If we can put i'th word to j'th word in one line
            // Here (j-i) is used for calculating space between words
            else if(cumulative_length[j+1]-cumulative_length[i]+(j-i) <= page_width)
                dp[i][j] = pow(page_width - (cumulative_length[j+1]-cumulative_length[i]+(j-i)), 2);
            // If we can't put i'th word to j'th word in one line then we put inf in dp array
            else
                dp[i][j] = inf;
        }
    }

    int min_cost[n];    // Here we will store min cost
    int path[n];        // This will be used to find combination of words
    for(int i=0; i<=n; i++)
        min_cost[i] = inf;  // Initializ

    for(int i=n-1; i>=0; i--){

        // If i'th word to last word can be written in one line then simply put value of dp array.
        // Path will store i'th word to which words are written in same line + 1.
        if(dp[i][n-1] != inf){
            min_cost[i] = dp[i][n-1];
            path[i] = n;
        }

        // If i'th word to last word can't be written in same line then we split in difrent position and take min cost
        for(int j=n-1; j>i; j--){

            // If dp[i][j-1] is inf then we can not split it here
            if(dp[i][j-1] != inf){
                if(min_cost[i] > dp[i][j-1]+min_cost[j]){
                    min_cost[i] = dp[i][j-1]+min_cost[j];
                    path[i] = j;
                }
            }
        }
    }

    // Print actual combination
    print_stringPath(st, path, n);

    return min_cost[0]; // Return min cost
}

void JUSTIFICATION::input_fun()
{
    string st[] = {"Tusher", "Roy", "likes", "to", "code"};
    int n = 5;

    int page_width = 10;

    int ans = text_justify(st, n, page_width);

    cout << "Min is: " << ans << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    JUSTIFICATION bc;
    bc.input_fun();
return 0;
}

