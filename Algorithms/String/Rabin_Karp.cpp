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
#define D 256               // Number of character
#define PRIME_CONSTANT 101  // Any constant number


class Rabin_Karp{
public:
    /*
     * Rabin Karp algorithm.
     * Average time complexity O(N + M)
     * Worst case Time Complexity O(N * M)
    */
    void input_fun();
    void searchh(string text, string pat);
};

void Rabin_Karp::searchh(string text, string pat)
{
    int pat_len = pat.length();
    int text_len = text.length();

    int H = 1;
    int hash_of_pat=0, hash_of_text=0;

    for(int i=0; i < pat_len-1; i++)        // Pow(D, pat_len-1);
        H = (H * D) % PRIME_CONSTANT;

    for(int i=0; i<pat_len; i++){
        hash_of_pat = ((D * hash_of_pat) + pat[i]) % PRIME_CONSTANT;    // Hash calculation
        hash_of_text = ((D * hash_of_text) + text[i]) % PRIME_CONSTANT;
    }

    for(int s=0; s <= (text_len - pat_len); s++){

        if(hash_of_pat == hash_of_text){    // If hash matches check for proper metch
            int i;
            for(i=0; i<pat_len; i++){
                if(pat[i] != text[i])
                    break;
            }
            if(i == pat_len)
                printf("Pattern found at index : %d\n", s);
        }

        if(s < text_len - pat_len){         // Delete starting index and add one index
            hash_of_text = (D * (hash_of_text - H * text[s]) + text[s+pat_len]) % PRIME_CONSTANT;

            if(hash_of_text < 0)        // This is important. For modulas operation very often negative value occurs.
                hash_of_text += PRIME_CONSTANT;     // So we need to make it positive.
        }
    }
}


void Rabin_Karp::input_fun()
{
    string text = "GEEKS FOR GEEKS";
    string pat = "GEEKS";
   // cin >> text >> pat;

    searchh(text, pat);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << hash_of_text << endl;

    Rabin_Karp bc;
    bc.input_fun();
return 0;
}

