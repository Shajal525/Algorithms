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
#define MAXC 256

struct TreeNode{            // This is node
    TreeNode *child[MAXC];
    TreeNode *suffixLink;
    int start;
    int *end;
    int suffixInd;
};

class SUFFIX_TREE{
    int end;
    int leafend;
    string text;
    TreeNode *root;
    TreeNode *activeNode;
    int activeEdge;
    int activeLength;
    int remaining_suffix;
    int size;
public:
    /*
     * Suffix tree is very hard to implement but it is very usefull.
     * This is Ukkonen's implementation of suffix tree.
     * Time complexity of building this suffix tree is O(N).
     *
     * Referance: geeksforgeeks.com and Tushar
     * There  is many application of suffix tree. Some of them are:
     * 1. Substring check in O(N) time
     * 2. Searching all patterns in O(N) time
     * 3. Longest repeated substring in O(N) time
     * 4. Build suffix array in O(N) time
     * 5. Generalized Suffix tree. This is used to build suffix tree of two or more strings.
     * 6. Longest common substring in O(N) time. Using generalized suffix tree.
     * 7. Longest palindromic substring. For this we should use Manacher's Algorithm O(N).
    */
    void input_function();
    void build_tree(string text);
    void extend_tree(int i);
    bool walkdown(TreeNode *curNode);
    TreeNode* create_node(int st, int *en);
    void print(int st, int en);
    void setSuffixIndexbyDFS(TreeNode *n, int lable_height);
    void find_pat(string st);
    bool find_pat_helper(TreeNode *n, string st, int ind);
    void build_suffix_array(int suffix_array[]);
    void build_suffix_array_healper(TreeNode *n, int suffix_array[], int *ind);
    void print_suffix_array(int suffix_array[]);
    int edgeLength(TreeNode *node){
        return *(node->end) - node->start + 1;
    }
};

TreeNode* SUFFIX_TREE::create_node(int st, int *en)     // Just creating new node with start and end.
{
    TreeNode *tmp = (TreeNode*)malloc(sizeof(TreeNode));
    tmp->start = st;
    tmp->end = en;
    tmp->suffixInd = -1;
    tmp->suffixLink = NULL;
    for(int i=0; i<MAXC; i++){
        tmp->child[i] = NULL;
    }
    return tmp;
}

bool SUFFIX_TREE::walkdown(TreeNode *curNode)
{
    if(activeLength >= edgeLength(curNode)){    // If activeLength is bigger or equal then

        activeEdge += edgeLength(curNode);      // Increase activeEdge
        activeLength -= edgeLength(curNode);    // Decrease activeLength
        activeNode = curNode;                   // Change active node
        return 1;
    }
    return 0;
}

void SUFFIX_TREE::extend_tree(int i)
{
    int ch = (int)text[i];
    leafend = i;            // Leaf end will increase each time

    remaining_suffix++;     // Remaining also increase

    TreeNode *lastNewNode = NULL;

    while(remaining_suffix > 0){
        if(activeLength == 0)       // If active Length is 0 then change active Edge.
            activeEdge = i;

        if(activeNode->child[(int)text[activeEdge]] == NULL){                   // Check if active edge exists
            activeNode->child[(int)text[activeEdge]] = create_node(i, &leafend);    // Just create new node.

            if(lastNewNode != NULL){
                lastNewNode->suffixLink = activeNode;
                lastNewNode = NULL;
            }
        }
        else{
            TreeNode *next = activeNode->child[(int)text[activeEdge]];  // Work with this child
            if(walkdown(next))  // This is easy to understand.
                continue;       // If true continue from while loop.

            if(text[next->start + activeLength] == ch){
                if(lastNewNode != NULL && activeNode != root){
                    lastNewNode->suffixLink = activeNode;
                    lastNewNode = NULL;
                }

                activeLength++;     // Increase length and break without decrimenting remaining.
                break;
            }

            int *splitEnd = (int*)malloc(sizeof(int));
            *splitEnd = next->start + activeLength -1;  // New end

            TreeNode *split = create_node(next->start, splitEnd);   // Create new chield
            activeNode->child[(int)text[activeEdge]] = split;       // New active node chield

            split->child[ch] = create_node(i, &leafend);    // New split
            next->start += activeLength;
            split->child[(int)text[next->start]] = next;    // Another side of split

            if(lastNewNode != NULL){
                lastNewNode->suffixLink = split;
            }

            lastNewNode = split;
        }

        remaining_suffix--;         // Decrement  remaining
        if(activeNode == root && activeLength > 0){     // If active Lenght greater then 0
            activeLength--;                         // Decrease active length
            activeEdge = i - remaining_suffix + 1;  // Increase active Edge
        }
        else if(activeNode != root){                // If it's not root
            activeNode = activeNode->suffixLink;    // just take suffix link
        }
    }
}

void SUFFIX_TREE::print(int st, int en)
{
    for(int k=st; k<=en; k++)
        printf("%c", text[k]);
}

void SUFFIX_TREE::setSuffixIndexbyDFS(TreeNode *n, int lable_height)
{
    if(n == NULL) return;

    if(n->start != -1){
        //print(n->start, *(n->end));
    }
    int leaf = 1;
    for(int i=0; i<MAXC; i++){

        if(n->child[i] != NULL){
           // if (leaf == 1 && n->start != -1)
             //   printf(" [%d]\n", n->suffixInd);

            leaf = 0;
            setSuffixIndexbyDFS(n->child[i], lable_height + edgeLength(n->child[i]));
        }
    }
    if (leaf == 1)
    {
        n->suffixInd = size - lable_height; // Suffix index update
       // printf(" [%d]\n", n->suffixInd);
    }
}

void SUFFIX_TREE::build_tree(string text)
{
    size = text.length();
    end = -1;
    root = create_node(-1, &end);   // Root isspecial node with start and end -1 always

    activeNode = root;      // Initially active node is root
    activeEdge = -1;
    leafend = -1;
    activeLength = 0;
    remaining_suffix = 0;

    for(int i=0; i<(int)text.length(); i++)
        extend_tree(i);     // Everything
    setSuffixIndexbyDFS(root, 0);       // Update suffix index
}

bool SUFFIX_TREE::find_pat_helper(TreeNode *n, string st, int ind)
{
    if(n == NULL)
        return 0;

    int i;
    for(i=n->start; i<=*(n->end) && st[ind] != '\0'; i++){
        if(text[i] != st[ind++])
            return 0;
    }

    if(st[ind] == '\0'){
        cout << "Pattern " << st << " found at index : " << i - st.length() << endl;
        return 1;
    }
    else{
        return find_pat_helper(n->child[(int)st[ind]], st, ind);
    }

    return 0;
}

void SUFFIX_TREE::find_pat(string st)
{
    if(find_pat_helper(root->child[(int)st[0]], st, 0) == 0)
        cout << "Pattern not found" << endl;
}

void SUFFIX_TREE::build_suffix_array_healper(TreeNode *n, int suffix_array[], int *ind)
{
    if(n == NULL)
        return;
    if(n->suffixInd == -1){
        for(int i=0; i<MAXC; i++){
            if(n->child[i] != NULL){
                build_suffix_array_healper(n->child[i], suffix_array, ind);
            }
        }
    }
    else if(n->suffixInd > -1 && n->suffixInd < size){
        suffix_array[(*ind)++] = n->suffixInd;
    }
   return;
}

void SUFFIX_TREE::build_suffix_array(int suffix_array[])
{
    int *ind = (int*)malloc(sizeof(int));
    *ind = 0;
    build_suffix_array_healper(root, suffix_array, ind);
    return;
}

void SUFFIX_TREE::print_suffix_array(int suffix_array[])
{
    for(int i=0; i<size; i++)
        cout << suffix_array[i] << " ";
    cout << endl;
}

void SUFFIX_TREE::input_function()
{
    //cin >> text;
    text = "THISISATESTTEXT$";
    size = sizeof(text);
    string pat = "IS A";

    build_tree(text);
   // find_pat(pat);
    int *suffix_array;
    size--;
    suffix_array = (int*)malloc(sizeof(int) * size);
    build_suffix_array(suffix_array);
    print_suffix_array(suffix_array);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    SUFFIX_TREE st;
    st.input_function();
}

