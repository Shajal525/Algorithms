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
#define PI 3.1415926535897932384626
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x<y?x:y
#define MAX_VAL 30000
//int SET(int n,int i) {return (n|(1<<i));}
//int RESET(int n,int i) {return (n&~(1<<i));}
//bool check(int n,int i) {return (n&(1<<i));}
using namespace std;

//Template Ends Here

struct Node{
    int val;
    struct Node *next;
};


class MERGESORT{
public:
    /*
     * Best Sorting algorithm for linked list.
     * Time Complexity: O(N * log N).
     * Space Complexity: O(1).
     * MergeSort take extra O(N) space for array but no extra space for LinkedList.
    */
    void input_fun();
    Node* createNode(int v);
    void push(Node **head_r, int val);
    void printList(Node *node);
    void findMid(Node *source, Node **left_h, Node **right_h);
    Node *merge(Node *left, Node *right);
    Node *mergeIterative(Node *left, Node *right);
    void mergeSort(Node **source);
};

Node* MERGESORT::createNode(int v)
{
    struct Node *t = (struct Node*)malloc(sizeof(Node));
    t->val = v;
    t->next = NULL;
    return t;
}

void MERGESORT::push(Node **head_r, int val)    // Insert element at the top
{
    struct Node *tmp = createNode(val);
    tmp->next = *head_r;
    *head_r = tmp;
}

void MERGESORT::printList(Node *node)
{
    while(node != NULL){
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

void MERGESORT::findMid(Node *source, Node **left_h, Node **right_h)    // This function finds mid and divide link list
{
    if(source == NULL || source->next == NULL){
       *left_h = source;
        *right_h = NULL;
        return;
    }

    Node *single_jump = source;
    Node *double_jump = source;
    while(double_jump->next != NULL){
        double_jump = double_jump->next;    // Jump once
        if(double_jump->next != NULL){
            single_jump = single_jump->next;    // Single jump
            double_jump = double_jump->next;    // Jump again
        }
    }
    *left_h = source;
    *right_h = single_jump->next;   // This is mid point
    single_jump->next = NULL;   // Divide link list. Now left_h and right_h are two link list
}

Node* MERGESORT::mergeIterative(Node *left, Node *right)    // Iterative version os merge function
{
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    Node *result = NULL;
    Node *head = NULL;  // We save head referance here

    if(left->val < right->val){ // Find head node
        result = left;
        left = left->next;
    }
    else{
        result = right;
        right = right->next;
    }
    head = result;  // Save head

    while(left != NULL && right != NULL){   // Iterate as normal merge function
        if(left->val < right->val){
            result->next = left;
            left = left->next;
        }
        else{
            result->next = right;
            right = right->next;
        }
        result = result->next;
    }
    if(left == NULL)
        result->next = right;
    else if(right == NULL)
        result->next = left;
    return head;    // Return head referance
}

Node* MERGESORT::merge(Node *left, Node *right) // This function is recursive because we want to return head referance
{
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    struct Node *result;

    if(left->val < right->val){
        result = left;
        result->next = merge(left->next, right);
    }
    else{
        result = right;
        result->next = merge(left, right->next);
    }
return result;
}

void MERGESORT::mergeSort(Node **source)
{
    if(*source == NULL || (*source)->next == NULL)
        return;

    struct Node *left = NULL;
    struct Node *right = NULL;

    findMid(*source, &left, &right);    // Find mid and divide the link list in two separate linklists

    mergeSort(&left);   // Recursievely do this for left and right.
    mergeSort(&right);

    *source = mergeIterative(left, right);   // Merge function returns head referance of result linklist after mergeing left and right
    //printArray(array, r);
return;
}

void MERGESORT::input_fun()
{
    struct Node *head = createNode(15);
    push(&head, 10);
    push(&head, 5);
    push(&head, 20);
    push(&head, 3);
    push(&head, 2);
    push(&head, 20);
    push(&head, 3);
    push(&head, 6);
    push(&head, 9);
    push(&head, 4);
    push(&head, 3);
    push(&head, 4);
    push(&head, 8);
    push(&head, 30);
    push(&head, 22);
    push(&head, 3);
    push(&head, 1);
    push(&head, 16);
    push(&head, 7);

    printList(head);
    mergeSort(&head);
    printList(head);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    MERGESORT bc;
    bc.input_fun();
return 0;
}

