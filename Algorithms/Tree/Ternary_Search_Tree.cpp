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
#define MAXV 5000

struct Node{
    char key;
    bool isLeaf;
    Node *left,*eq,*right;

    Node(char k){
        key = k;
        isLeaf = 0;
        left = right = eq = NULL;
    }
};

class TernarySearchTree{
public:
    /*
     * Ternary Search can used instade of Binary Search. For this we need to take 2 mid in BS
     * and declare 3 recursive call instade of two. This is a tad more efficient.
     *
     * Here we are dealing with Ternary Search Tree.
     * This is used for Auto Complete text in browser and search engine
     * This is advanced form of Trie. Here we dont need extra 26 charecter array in each Node.
     * While insert if a charecter is less then root charecter then we will go left and if
     * charecter is bigger then root key then we go right. But if the charecter is same then we
     * go toward middle node. This move help us making trie with less memory.
     *
     * Time complexity for all function is same as BST.
     * Ref.: geeksforgeeks
    */
    void traverseUtil(Node *root, char *buffer, int index);
    void traverse(Node *root);
    bool search(Node *&root, char *key);
    void insert(Node *&root, char *key);
    void input_fun();
};

void TernarySearchTree::traverseUtil(Node *root, char *buffer, int index)
{
    if(root == NULL)
        return;

    traverseUtil(root->left, buffer, index);    // We go left. Note: We don't increment index here

    buffer[index] = root->key;  // Save key in buffer.
    if(root->isLeaf == 1){  // If this is leaf we print it

        buffer[index+1] = '\0';
        cout << buffer << endl;
    }

    // If we move middle then we are taking this charecter. So we increment index here
    traverseUtil(root->eq, buffer, index+1);

    // We go right. Note: We dno't increment index here
    traverseUtil(root->right, buffer, index);
}

void TernarySearchTree::traverse(Node *root)
{
    char buffer[MAXV];  // For saving charecter for print
    traverseUtil(root, buffer, 0);
}

bool TernarySearchTree::search(Node *&root, char *key)
{
    if(root == NULL)
        return false;

    if(root->key > *key)
        return search(root->left, key);

    else if(root->key < *key)
        return search(root->right, key);

    // If the key matches we inter here
    else{
        // If this is not last charecter in the search keythen we go farther through middle node
        if(*(key+1) != '\0')
            return search(root->eq, key+1);
        // If this is last charecter in key string
        else
            return root->isLeaf;
    }
}

void TernarySearchTree::insert(Node *&root, char *key)
{
    // If root is NULL we create new Node here.
    // Note: We don't return from here. So next conditions will also execute after creating new Node
    if(root == NULL)
        root = new Node(*key);

    if(root->key > *key)
        insert(root->left, key);

    else if(root->key < *key)
        insert(root->right, key);

    // If key matches this is either already existed in our tree or we created this node
    // in above root == NULL if condition. In either cases the charecter matches
    else{
        // If this is not last charecter we go farther from middle node. We increase key
        // because this key is now saved.
        if(*(key+1) != '\0')
            insert(root->eq, key+1);
        // If this is last charecter in insert key then we make this a leaf node.
        else
            root->isLeaf = 1;
    }
}

void TernarySearchTree::input_fun()
{
    struct Node *root = NULL;

    // Ignore warnings
    insert(root, "cat");
    insert(root, "cats");
    insert(root, "up");
    insert(root, "bug");

    printf("Following is traversal of ternary search tree\n");
    traverse(root);

    printf("\nFollowing are search results for cats, bu and cat respectively\n");
    search(root, "cats") ? printf("Found\n"): printf("Not Found\n");
    search(root, "bu")   ? printf("Found\n"): printf("Not Found\n");
    search(root, "cat")  ? printf("Found\n"): printf("Not Found\n");

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    TernarySearchTree bc;
    bc.input_fun();
return 0;
}

