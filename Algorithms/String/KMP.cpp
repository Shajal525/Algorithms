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


class KMP{
    int lps[MAX_VAL];
    bitset<MAX_VAL> visited;
public:
    void initializ(){
    }
    /*
     * Time Complexity: O(n)

        This algorithm is used to match pattern. Suppose given a pattern, we have to find number
        of occurance of that pattern in a text field. That can be done in O(n) worse case time complexity
        using this algorithm.
    */

    void input_fun();
    void preprocess(string pat);    // This algorith requirs some preprocess in pattern to create LPS array.
                                    // LPS=Largest Prefix which is also a suffix
    void KMP_search(string text, string pattern);   // Main function
};

void KMP::preprocess(string pat)
{
    int n = pat.length();

    lps[0] = 0;
    int i = 1;
    int len = 0;    // len will change

    while(i < n){
        if(pat[i] == pat[len]){     // Increase both i, len
            lps[i] = ++len;
            i++;
        }
        else{
            if(len != 0){
                // AAAABBAAAAABB
                len = lps[len - 1];     // Not increasing i
            }
            else{
                lps[len] = 0;
                i++;
            }
        }
    }
}

void KMP::KMP_search(string text, string pattern)
{
    int n = text.length();
    int i=0;
    int len = 0;
    bool flag = 1;

    preprocess(pattern);

    while(i < n){
        if(len == (int)pattern.length())
        {
            flag = 0;
            cout << "Pattern found at index : " << i - len << endl;
            len = lps[len - 1];
        }
        else if(text[i] == pattern[len]){
            i++,len++;
        }
        else{
            if(len != 0)
                len = lps[len-1];
            else
                i++;
        }
    }
    if(flag){
        cout << "No pattern found" << endl;
    }
}

void KMP::input_fun()
{
    string pattern, text;
    cin >> text >> pattern;

    KMP_search(text, pattern);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    KMP bc;
    bc.input_fun();
return 0;
}

