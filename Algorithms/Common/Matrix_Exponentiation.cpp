//My Template Starts Here

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
#define ll long long
#define ui unsigned int
#define MP make_pair
#define INPUT freopen("C://Users/Shajal/Desktop/input.txt", "r+", stdin)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define sc scanf
#define pf printf
#define out std::cout
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

//My Template Ends Here

#define V 2    // This is number of row and column in matrix

class MATRIX{
public:

    /*
        Reference: http://codeforces.com/blog/entry/43225
        This reference is  very very useful.

        Application 1: [Counting the number of ways for reaching a vertex].
        You are given an unweighted directed graph (may contain multiple edges) containing N
        nodes (1 <= N <= 200) and an integer b (1 <= b <= 10^9). You are also given Q queries (1 <= Q <= 10^5).
        For each query you are given two nodes u and v and you have to find the number of ways for reaching vertex v
        starting from u after exactly b steps. (A step is passing through an edge. Each edge may be passed multiple number of times).

        Solution:
        Let M1 be a matrix where M1[i][j] equals the number of edges connecting vertex i to vertex j.
        Let M2 be M1 raised to the power of b (M1^b). Now for any pair u and v, the number of ways for reaching vertex v
        starting from u after b steps is M2[u][v].
        Practice problem: 621E, UVa 336(solved).


        Application 2: [Shortest path with a specified number of steps].
        You are given a weighted graph containing N nodes (1 <= N <= 200) and an integer b (1 <= b <= 10^9).
        You are also given Q queries (1 <= Q <= 10^5). For each query you are given two nodes u and v and you have to
        find the minimum cost for reaching vertex v starting from u after exactly b steps. (A step is passing through an edge.
        Each edge may be passed multiple number of times).

        Solution:
        Let M1 be a matrix where M1[i][j] equals the cost of passing the edge connecting i to j (infinity if there is no edge).
        Let M2 be M1 raised to the power of b (but this time using the distance product for multiplication).
        Now for any pair u and v, the minimum cost for reaching vertex v starting from u after b steps is M2[u][v].
        Practice problem: 147B

        This is very powerful algorithm. Using matrix exponentiation we can solve many complex problems.
        We can solve Fibonacci number problem using this algorithm in O(log N) time.
        We can also solve any linear recursive problem using matrix exponentiation.


    */
    /*
        Application 1: Counting the number of ways for reaching a vertex.
        Works for unweighted graph.
    */
    int num_of_way_using_b_steps(int mat[V][V], int b);

    /*
        Application 2: Shortest path with a specified number of steps.
        This works for weighted graph.
    */
    int shortest_path_using_b_steps(int mat[V][V], int b);
    void distance_product_multiply(int mat1[][V], int mat2[][V]);

    void Fibonacci();

    void matrix_exponentiation(int mat[V][V], int b);
    void power_of_matrix(int mat[V][V], int initial_mat[V][V], int p);
    void multiply(int mat1[][V], int mat2[][V]);

};

void MATRIX::multiply(int mat1[][V], int mat2[][V])     // Answer will be saved in 1'st matrix
{
    int res[V][V];

    for(int i=0; i<V; i++){     // Row's of matrix

        for(int j=0; j<V; j++){     // Columns of matrix.

            res[i][j] = 0;      // Initially result is zero.

            for(int k=0; k<V; k++){                    // For all k (i'th row's k'th column + j'th columns k row)
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Copy res into mat1
    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            mat1[i][j] = res[i][j];
return;
}

// Matrix exponentiation using divide and conquer method.
void MATRIX::power_of_matrix(int mat[V][V], int initial_mat[V][V], int p)
{
    if(p <= 1)
        return;

    power_of_matrix(mat, initial_mat, p/2);     // Recursive divide and conquer call

    multiply(mat, mat);

    if(p & 1)
        multiply(mat, initial_mat);

return;
}

void MATRIX::matrix_exponentiation(int mat[V][V], int b)
{
    int initial_mat[V][V] = { {1,1}, {1,0} };   // This is same as Mat. This is needed in power_of_matrix function

    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            initial_mat[i][j] = mat[i][j];

    power_of_matrix(mat, initial_mat, b);

return;
}

void MATRIX::Fibonacci()
{
    // Fibonacci Formula F(n) = F(n-1) + F(n-2)

    // For Fibonacci series.
    int mat[V][V] = {{1,1}, {1,0} };

    int n = 5; // For 5'th Fibonacci number

    matrix_exponentiation(mat, n-1);

    int fib[V][1] = {1, 0};

    cout<< mat[0][0] * 1 + mat[0][1] * 0;   // For Fibonacci F(1) = 1 and F(0) = 0. So after multiply mat with fib result is mat[0][0].
}

int MATRIX::num_of_way_using_b_steps(int mat[V][V], int b) // Here mat is unweighted adjacency matrix
{
    matrix_exponentiation(mat, b);
    // Now mat is number of way to reach from any U to V using b steps.

}


void MATRIX::distance_product_multiply(int mat1[][V], int mat2[][V])     // Answer will be saved in 1'st matrix
{
    int res[V][V];

    for(int i=0; i<V; i++){     // Row's of matrix

        for(int j=0; j<V; j++){     // Columns of matrix.

            res[i][j] = INT_MAX;      // Initially result is zero.

            for(int k=0; k<V; k++){                    // For all k (i'th row's k'th column + j'th columns k row)
                res[i][j] = min(res[i][j], mat1[i][k] * mat2[k][j]);
            }
        }
    }

    // Copy res into mat1
    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            mat1[i][j] = res[i][j];
return;
}
int MATRIX::shortest_path_using_b_steps(int mat[V][V], int b)  // Here mat is weighted adjacency matrix.
{
    matrix_exponentiation(mat, b);
    // Now mat is shortest path to reach from any U to V using b steps.
}

int main()
{
    MATRIX MT;
    MT.Fibonacci();
return 0;
}
