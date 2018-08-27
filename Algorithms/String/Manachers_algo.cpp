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

#define MAXVAL 5000


class MANACHER{
    int size;
    char text[MAXVAL];          // Main text
    char processedText[MAXVAL]; // Processed for dealing with even longth palindroms. Ex: for "abccba" converted to "$a$b$c$c$b$a$"
public:
    /*
     * This is Manacher's algorithm for finding Longest Palindromic Substring.
     * This algorithm works in O(N) time.
     * Best algorithm for Palindrom search.
     * Reference: Tushar
     * We can also do this using DP but is best technic.
     * If we need to find Longest Palindromic Subsequence then we must use DP. Can take help from Tushar.
     */
    void input_fun();
    bool boundryCheck(int low, int high){
        return (low >= 0 && high < size) ? 1 : 0;   // Boundry check
    }
    void find_longestPalindromicSubstring(char text[]);
    void processTextForEvenPalindrom(char text[]);
    void maxPal(int arr[]);
};

void MANACHER::processTextForEvenPalindrom(char text[]) // Add '$' after each charecter. Ex. for "aca" it become "$a$c$a"
{
    int ind = 0;

    processedText[0] = '$';
    for(int i=1; ind < size; i+=2){
        processedText[i] = text[ind++];
        processedText[i+1] = '$';
    }
    size = 2 * size + 1;    // Double the size
    return;
}

void MANACHER::maxPal(int arr[])
{
    int mx = INT_MIN;
    int ind = -1;
    for(int i=0; i<size; i++){
        if(mx < arr[i])             // Find max value
            mx = arr[i], ind = i/2; // Index half for original text.
    }
    mx /= 2;    // Half for original text

    int startInd = ind - mx / 2;
    cout << "Longest palindrom substring for \"" << text << "\" is : \"";
    for(int in=startInd; in< startInd+mx; in++)
        cout << text[in];
    cout << "\"" << endl;
    return;
}

void MANACHER::find_longestPalindromicSubstring(char text[])
{
    processTextForEvenPalindrom(text);  // Process text.

    int start=0, end = 0;
    int longestPalForThisCenter[size];
    memset(longestPalForThisCenter, 0, sizeof(longestPalForThisCenter));

    int mirror, newCenter;
    for(int i=0; i<(int)strlen(processedText); ){
        while(boundryCheck(start-1, end+1) && processedText[start-1] == processedText[end+1])
            --start, ++end;     // Matched Palindrom start and end index

        longestPalForThisCenter[i] = end - start + 1;   //  Substitute Palindrom length

        if(end == size - 1)
            break;
        newCenter = end + 1;    // Initially new center is end index plus 1

        for(int j=i+1; j<=end; j++){
            mirror = i - (j - i);   // Mirror of this index
            longestPalForThisCenter[j] = min(longestPalForThisCenter[mirror], 2 * (end - j) + 1);

            if(j + longestPalForThisCenter[mirror] / 2 == end){ // If palindrom at mirror index ends at end index
                newCenter = j;      // Change new Center and stop;
                break;
            }
        }
        i = newCenter;  // Update i, start and end
        start = newCenter - longestPalForThisCenter[newCenter] / 2;
        end = newCenter + longestPalForThisCenter[newCenter] / 2;
    }

    maxPal(longestPalForThisCenter);    // Search max in this array and print max Palindrom.
return;
}

void MANACHER::input_fun()
{
    strcpy(text, "babcbabcbaccba");
    size = strlen(text);
    find_longestPalindromicSubstring(text);

    strcpy(text, "abaaba");
    size = strlen(text);
    find_longestPalindromicSubstring(text);

    strcpy(text, "abababa");
    size = strlen(text);
    find_longestPalindromicSubstring(text);

    strcpy(text, "abcbabcbabcba");
    size = strlen(text);
    find_longestPalindromicSubstring(text);

    strcpy(text, "forgeeksskeegfor");
    size = strlen(text);
    find_longestPalindromicSubstring(text);

    strcpy(text, "caba");
    size = strlen(text);
    find_longestPalindromicSubstring(text);

    strcpy(text, "abacdfgdcaba");
    size = strlen(text);
    find_longestPalindromicSubstring(text);

    strcpy(text, "abacdfgdcabba");
    size = strlen(text);
    find_longestPalindromicSubstring(text);

    strcpy(text, "abacdedcaba");
    size = strlen(text);
    find_longestPalindromicSubstring(text);

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    MANACHER bc;
    bc.input_fun();
return 0;
}

