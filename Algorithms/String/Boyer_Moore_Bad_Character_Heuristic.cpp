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

#define NUM_OF_CHAR 256

class Boyer_Moore{
    int last_ind_of_bad_c[NUM_OF_CHAR];
public:

    /* This is Boyer Moore Algorithm based on Bad Character Heuristic. Here bad character means last char in text that not
     * mathes with pattern. We preprocess the last index of each character then start search from reverse side
     *
     * Worst case Time Complexity N(M * N)
     * Best Case N(M/N)
    */
    Boyer_Moore(){
        for(int i=0; i<NUM_OF_CHAR; i++)    // initializ with -1
            last_ind_of_bad_c[i] = -1;
    }
    void input_fun();
    void preprocessing(string pat);
    void searchh(string text, string pat);
};

void Boyer_Moore::preprocessing(string pat)
{
    for(int i=0; i<(int)pat.length(); i++)
        last_ind_of_bad_c[(int)pat[i]] = i;     // Last index of each character
}

void Boyer_Moore::searchh(string text, string pat)
{
    preprocessing(pat);

    int pat_len = pat.length();
    int text_len = text.length();

    bool fl = 1;
    int s = 0;

    while(s <= (text_len - pat_len)){
        int j = pat_len -1;

        while(j >= 0 && pat[j] == text[s+j])    // Start checking from bask side of pattern
            j--;

        if(j < 0){  // Pattern found
            printf("Pattern foun at index: %d\n", s);
            s++;
            fl =0;
        }
        else{   // Increase S at least 1 or last index of bad charecter.
            s += max(1, j - last_ind_of_bad_c[(int)text[s+j]]);
        }
    }
    if(fl)
        printf("Pattern  not found\n");
    return;
}

void Boyer_Moore::input_fun()
{
    string text, pat;
    cin >> text >> pat;

    searchh(text, pat);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Boyer_Moore bc;
    bc.input_fun();
return 0;
}

