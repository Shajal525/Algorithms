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
#define MAX_STATE 500
#define MAXC 26


class Aho_Corasick{
    int trie[MAX_STATE][MAXC];  // Make trie in two dimentional array
    int outb[MAX_STATE];        // This is to save pattern that matches in current state using bit
    int fall[MAX_STATE];        // Index of fall
public:
    /*
     * Aho Corasick algorithm. This is bast if there is a number of pattern and we need all the occurance of that patterns.
     * Time complexity O(N + M + K).
     * K is number of pattern.
     * Preprocess Patterns.
     * But preprocessing is a bit complex.
     * Referance : geeksforgeeks.com
    */
    void input_fun();
    void preprocessing(string pats[], int k);
    int find_next_state(int state, char ch);
    void searchh(string text, string pats[], int k);

};

void Aho_Corasick::preprocessing(string pats[], int k)
{
    for(int i=0; i<MAX_STATE; i++){     // Initializaton
        outb[i] = 0;
        fall[i] = -1;
        for(int j=0; j<MAXC; j++)
            trie[i][j] = -1;
    }

    int state = 1;

    for(int i=0; i<k; i++){     // In this part make the trie
        string st = pats[i];
        int l = st.length();
        int current_state = 0;

        for(int j=0; j<l; j++){
            int ch = st[j] - 'a';

            if(trie[current_state][ch] == -1)       // Make state for each word
                trie[current_state][ch] = state++;

            current_state = trie[current_state][ch];    // Make chield current
        }
        outb[current_state] |= (1 << i);            // Here a patern ends. So that is output
    }

    queue<int> qu;

    for(int ch=0; ch<MAXC; ch++){
        if(trie[0][ch] != -1){
            fall[trie[0][ch]] = 0;  // All chield of root fall at root
            qu.push(trie[0][ch]);   // Push chields to queue
        }
        else
            trie[0][ch] = 0;     // All non existing root childrens indicates next state 0. This will help
    }

    while(!qu.empty()){
        int cur_state = qu.front();
        qu.pop();

        for(int ch = 0; ch<MAXC; ch++){
            if(trie[cur_state][ch] != -1){          // If the chield exists
                int  fall_state = fall[cur_state];  // Find parents fall

                while(trie[fall_state][ch] == -1)   // If fall state has no children ch then
                    fall_state = fall[fall_state];  // we take fall's fall. This will continue until we reach root.

                fall[trie[cur_state][ch]] = trie[fall_state][ch];   // Fall of current state's ch is fall's matched ch

                outb[trie[cur_state][ch]] |= outb[trie[fall_state][ch]];    // Now output strings of fall's ch will be also
                                                                            // output of this stats ch
                qu.push(trie[cur_state][ch]);
            }
        }
    }
}

int Aho_Corasick::find_next_state(int state, char ch)
{
    int ans = state;
    int chr = ch - 'a';

    while(trie[ans][chr] == -1)     // If not matches then climb up to the root
        ans = fall[ans];

    return trie[ans][chr];
}

void Aho_Corasick::searchh(string text, string pats[], int k)
{
    preprocessing(pats, k);

    int curr_state = 0;
    for(int i=0; i<(int)text.length(); i++){

        curr_state = find_next_state(curr_state, text[i]);  // Find match of text[i] from current state

        if(outb[curr_state] != 0){  // If there is output strings in this state

            for(int j=0; j<MAXC; j++){

                if(outb[curr_state] & (1 << j)){
                    cout << "String " << pats[j] << " found from " << i-pats[j].length()+1 << " to " << i << endl;
                }
            }
        }
    }
}

void Aho_Corasick::input_fun()
{
    string text = "ahishers";
    string pats[] = {"he", "she", "hers", "his"};
    int k = (int)(sizeof(pats) / sizeof(pats[0]));

    searchh(text, pats, k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Aho_Corasick bc;
    bc.input_fun();
return 0;
}

