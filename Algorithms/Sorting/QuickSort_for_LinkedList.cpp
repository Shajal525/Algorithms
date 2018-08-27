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

class QUICKSORT{
public:
    /*
     * Merge sort is prefered over This algorithm for LinkedList.
     * Time Complexity: Worst Case: O(N * N) but Average Case: O(N Log N).
     * Space Complexity: O(1).
     * Here worst case is very rare.
    */
    void input_fun();
    Node *createNode(int val);
    void push(Node **head_r, int val);
    Node *getTail(Node *node);
    void printList(Node *node);
    Node* partition(Node *head, Node *tail);
    void quickSortUtil(Node *head, Node *tail);
    void quickSort(Node **head);
};

Node* QUICKSORT::createNode(int val)
{
    struct Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

void QUICKSORT::push(Node **head_r, int val)    // Insert element at the top
{
    struct Node *tmp = createNode(val);
    tmp->next = *head_r;
    *head_r = tmp;
}

Node* QUICKSORT::getTail(Node *node)    // Last Node
{
    if(node == NULL)
        return NULL;
    while(node->next != NULL)
        node = node->next;
    return node;
}

void QUICKSORT::printList(Node *node)
{
    while(node != NULL){
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

Node* QUICKSORT::partition(Node *head, Node *tail) // Main trick is here.
{
    Node *pivot = tail; // Last element as pivot
    Node *node = head; // This maintain everything
    Node *pre_node = head;  // previous node of *node
    Node *curr = head;  // This works like for loop i
    while(curr != tail){
        if(curr->val < pivot->val){
            int t = curr->val;      // Swap value. We can also change total referance but this is easier.
            curr->val = node->val;
            node->val = t;

            pre_node = node;    // save previous node
            node = node->next;  // Go to next node
        }
        curr = curr->next;  // Loop increase
    }
    int t = node->val;  // Swap with pivot
    node->val = pivot->val;
    pivot->val = t;
    return pre_node;    // Return privious node. If i return *node then it will fall in infinite loop for already sorted list
}

void QUICKSORT::quickSortUtil(Node *head, Node *tail)    // Easy part
{
    if(head == NULL || head == tail)
        return;
    Node *p = partition(head, tail);    // Returns previous node of pivot node

    quickSortUtil(head, p); // From head to p
    if(p->next != tail) // Must check this
        quickSortUtil(p->next->next, tail); // p->next is pivot. So we need to use p->next->next
}

void QUICKSORT::quickSort(Node **head)
{
    quickSortUtil(*head, getTail(*head));
    return;
}

void QUICKSORT::input_fun()
{
    Node *head = createNode(5);
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
    quickSort(&head);
    printList(head);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    QUICKSORT bc;
    bc.input_fun();
return 0;
}

