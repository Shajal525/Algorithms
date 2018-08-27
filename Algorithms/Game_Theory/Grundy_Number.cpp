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


class GRUNDY{
public:
    /*
     * If we are given more then one pile of stone and we can take some fixed number of stones from any pile
     * then we have to solve it using Grundy Number theorum. If we can take any number of stones then we can
     * simply XOR all numbers and get the result as shown in previous note. But here we need to determine
     * Grundy number for each pile of stone. Groundy number is a number which converts those piles into
     * normal piles with some stone.
     *
     * How to find Grundy number? If we can take 1, 2 or 3 stones from each pile then for N stones
     * Groundy og N is Grundy(n) = Minimum_Value_Excluded{Grundy(n-1), Gruncy(N-2), Grundy(N-3)}.
     * Here Minimum_Value_Excluded or MEX is the minimum value that is not present in the given set.
     *
     * After finding Grundy number for each pile we can simply XOR thpse number and get our answer.
     *
     * Time Complexity: For building GrundyArray it will
     * take O(N * NumberOfPossibleMove * log(NumberOfPossibleMove)).
     * If NumberOfPossibleMove is very small then it's equavalent to O(N).
     *
     * Sometimes there will be pattern. So we don't need to calculate Grundy. We can simply mod and find
     * required value. So we must check for pattern in this kind of problem. The example problem used here
     * also has a pattern. GrundyArray[] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, .........}
     * We can easily see this is a pattern.
    */
    int minimumValueExcluded(int array[], int n);
    int minimumValueExcludedUsingSet(set<int> &moves);
    void calculateGrundyNumberArrayUsingDP(int GrundyNumber[], int size);
    void grundyGame(int PileArray[], int n, int maxSizePile);
    void input_fun();
};

// Minimum Value Excluded or MEX
// That means minimum value that is not present in the given array
// This can be done easily if we save value in a set and use set.find() function
int GRUNDY::minimumValueExcluded(int array[], int n)
{
    int val = 0;
    bool found = true;

    // This loop will run until there is no value in array equal to 'val'
    while(found){

        found = false;  // Initially found is false

        for(int i=0; i<n; i++){
            if(array[i] == val){    // If val is found in array
                val++;              // Increment val
                found = true;       // found is now true
                break;
            }
        }
    }

    return val;
}

int GRUNDY::minimumValueExcludedUsingSet(set<int> &moves)
{
    int i = 0;

    while(moves.find(i) != moves.end())
        i++;

    moves.clear();
    return i;
}

void GRUNDY::calculateGrundyNumberArrayUsingDP(int GrundyNumber[], int size)
{
    // Remember we can take 1,2 or 3 stone at a time

    // This is looping position
    GrundyNumber[0] = 0;
    // If there is 1 stone then we can take that stone and then there is last 0 stone. So MEX of {Grundy(0)}
    // or {0} is 1
    GrundyNumber[1] = 1;
    // If there is 2 stone then we can take 1 or 2 stone so there is left 1 or 0 stone. So MEX of
    // {Grundy(0),Grundy(1)} or {0, 1} is 2
    GrundyNumber[2] = 2;
    // If there is 3 stone then we can take 1 or 2 or 3 stone so there is left 2 or 1 or 0 stones. So MEX of
    // {Grundy(0),Grundy(1), Grundy(2)} or {0, 1, 2} is 3
    GrundyNumber[3] = 3;

    // If there is 4 stone then we can take 1 or 2 or 3 stone so there is left 3 or 2 or 1 stones. So MEX of
    // {Grundy(1),Grundy(2), Grundy(3)} or {1, 2, 3} is 0
    // We will calculate this using DP.
    GrundyNumber[4] = 0;
    set<int> moves;

    for(int i=4; i<=size; i++){
        // Temporary array for Grundy of all positions where we can go from this position.
        //int tmpArray[3] = {GrundyNumber[i-1], GrundyNumber[i-2], GrundyNumber[i-3]};

        // Now find Minimum Value Excluded in that array
        //GrundyNumber[i] = minimumValueExcluded(tmpArray, 3);

        // This can be done using Set
        moves.insert(GrundyNumber[i-1]);
        moves.insert(GrundyNumber[i-2]);
        moves.insert(GrundyNumber[i-3]);

        GrundyNumber[i] = minimumValueExcludedUsingSet(moves);
    }
//    This is for printing Grundy array
//    for(int i=0; i<=size; i++){
//        cout << GrundyNumber[i] << " ";
//    }
//    cout << endl;
    return;
}

void GRUNDY::grundyGame(int PileArray[], int n, int maxSizePile)
{
    int GrundyNumber[maxSizePile];

    calculateGrundyNumberArrayUsingDP(GrundyNumber, maxSizePile);

    int XOR = 0;

    // Calculate XOR of Grundy Number for each Pile of Stone
    for(int i=0; i<n; i++){

       XOR ^= GrundyNumber[ PileArray[i] ];
    }

    if(XOR == 0)
        cout << "Player 2 win's!!" << endl;
    else
        cout << "Player 1 win's!!" << endl;
}

void GRUNDY::input_fun()
{
    int pileArray[] = {13, 45, 23, 26};
    int n = sizeof(pileArray)/sizeof(pileArray[0]);
    int mxPile = 45;

    grundyGame(pileArray, n, mxPile);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    GRUNDY bc;
    bc.input_fun();
return 0;
}

