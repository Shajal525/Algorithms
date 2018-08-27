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
struct Node{
    char ch;
    int frequency;

    Node *left, *right;
    Node(){}
    Node(char c, int fre): ch(c), frequency(fre){
        left = right = NULL;
    }
    bool operator<(const Node& nn)const{ //This won't work for pointer. No way to do this for pointer
        return this->frequency < nn.frequency;
    }
};


class HUFFMAN{
public:
    /*
     * Huffman Coading is a lossless data compression algorithm.
     * The idea is to assign variable-length codes to input characters, lengths of the assigned
     * codes are based on the frequencies of corresponding characters. The most frequent character
     * gets the smallest code and the least frequent character gets the largest code.
     *
     * The variable-length codes assigned to input characters are Prefix Codes, means the
     * codes (bit sequences) are assigned in such a way that the code assigned to one character is not
     * prefix of code assigned to any other character. This is how Huffman Coding makes sure that there
     * is no ambiguity when decoding the generated bit stream.
     *
     * There are mainly two major parts in Huffman Coding
     * 1) Build a Huffman Tree from input characters.
     * 2) Traverse the Huffman Tree and assign codes to characters.
     *
     * Time Complexiy: O(N*logN) for building Huffman tree
     * Referance: geeksforgeeks.com
    */
   // static bool compare(Node *l, Node *r);
    void PrintCodes(Node *node, string st);
    Node *buildHuffmanTree(char charArray[], int freqArray[], int n);
    void input_fun();
};

struct compare{
    bool operator ()(Node *l, Node *r){
        return l->frequency > r->frequency;
    }
};

void HUFFMAN::PrintCodes(Node *node, string st)
{
    if(node == NULL)
        return;

    // If ch != '$' that means its leaf
    if(node->ch != '$')
        cout << node->ch << " : " << st << endl;

    PrintCodes(node->left, st + "0");   // Add Zero to path if we move left
    PrintCodes(node->right, st + "1");  // Add One to path if we move right
}

Node* HUFFMAN::buildHuffmanTree(char charArray[], int freqArray[], int n)
{
    // For ascending order or min Heap this is only way to use Priority Queue
    // Operator overload wont work for pointer. If we use Node instade of Node* in Priority Queue then
    // we can use operator overload.
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Make minHeap with chars and frequencys
    for(int i=0; i<n; i++)
        minHeap.push(new Node(charArray[i], freqArray[i]));

    // When there is only one node left in priority queue then we quit the loop
    while(minHeap.size() != 1){
        // Take the minimum node and this will be our left chield
        Node *left = minHeap.top();
        minHeap.pop();  // Pop it

        // Take next minimum is our right chield
        Node *right = minHeap.top();
        minHeap.pop();

        // Make new node with char '$' and frequency is sum of left and right frequency
        Node *newNode = new Node('$', left->frequency + right->frequency);

        newNode->left = left;   // Make this left chield
        newNode->right = right; // Make it right chield

        minHeap.push(newNode);  // Push in queue
    }

    return minHeap.top();   // This is the root. Return the root
}

void HUFFMAN::input_fun()
{
    char charArray[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freqArray[] = {5, 9, 12, 13, 16, 45};

    int n = sizeof(freqArray)/sizeof(freqArray[0]);

    Node *root = buildHuffmanTree(charArray, freqArray, n);

    PrintCodes(root, "");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    HUFFMAN bc;
    bc.input_fun();
return 0;
}

