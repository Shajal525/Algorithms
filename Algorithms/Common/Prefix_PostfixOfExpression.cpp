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


class EXPRESSION_PRE_POS{
public:
    /*
     * Infix expression to Prefix and Postfix expression.
    */
    void input_fun();
    bool is_operand(char c);
    int precedence(char operatorr);
    string infix_to_postfix(string exp);
    string infix_to_prefix(string exp);
};

bool EXPRESSION_PRE_POS::is_operand(char c)
{
    if(c >= '0' && c <='9') // Operand can be alphabet
        return true;
    return false;
}

int EXPRESSION_PRE_POS::precedence(char operatorr)
{
    if(operatorr == '+' || operatorr == '-')    // Precedance of + and - is same
        return 1;
    else if(operatorr == '*' || operatorr == '/')   // Precedance of * and / is same but greater then +,-
        return 2;
    else if(operatorr == '^')   // Highest precedance
        return 3;
    return -1;  // This will help in our algorithm
}

string EXPRESSION_PRE_POS::infix_to_postfix(string exp)
{
    int l = exp.length();
    stack<char> stk;
    string ans;
    for(int i=0; i<l; i++){
        if(is_operand(exp[i]))  // If operand then put it in ans string
            ans += exp[i];
        else if(exp[i] == '(')  // Put in stack
            stk.push('(');
        else if(exp[i] == ')'){
            while(!stk.empty() && stk.top() != '('){
                ans += stk.top();   // Take operator until we reach '(' or finish everything
                stk.pop();
            }
            if(!stk.empty())    // If stk.top() = '(' pop it out
                stk.pop();
        }
        else{   // If we get operator
            // If precedance of this is less or equalto then previous operator take previous one else stop
            while(!stk.empty() && precedence(stk.top()) >= precedence(exp[i])){
                ans += stk.top();
                stk.pop();
            }
            stk.push(exp[i]);   // Push this operator in stack
        }
    }
    while(!stk.empty()){    // At the end take everything from stack
        ans += stk.top();
        stk.pop();
    }

    return ans;
}

string EXPRESSION_PRE_POS::infix_to_prefix(string exp)
{
    // We can obtain prefix from postfix.
    // To get prefix we need to reverse the string. So '(' will become ')' and '(' become ')'.
    // Then we need to find its postfix and reverse that result. Thats it!
    reverse(exp.begin(), exp.end());
    int l = exp.length();
    for(int i=0; i<l; i++){
        if(exp[i] == '(')
            exp[i] = ')';
        else if(exp[i] == ')')
            exp[i] = '(';
    }

    string res = infix_to_postfix(exp);

    reverse(res.begin(), res.end());

    return res;
}

void EXPRESSION_PRE_POS::input_fun()
{
    string exp;
    cin >> exp;
    cout << "Original string: " << exp << endl;
    cout << "Postfix: " << infix_to_postfix(exp) << endl;
    cout << "Prefix: " << infix_to_prefix(exp) << endl;
}


int main()
{
    freopen("/home/shajal/Desktop/inp.txt", "r+", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    EXPRESSION_PRE_POS bc;
    bc.input_fun();
return 0;
}

