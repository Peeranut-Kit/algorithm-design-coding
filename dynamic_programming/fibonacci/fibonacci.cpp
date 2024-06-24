#include <iostream>
using namespace std;

int table[11];

// Dynamic Programming = Divide & Conquer + Lookup Table

// Recurrent Relation
// T(n) = T(n-1) + T(n-2) + O(1) => O(2^n)
int fibo_RR(int n)
{
    if (n == 0 || n == 1)
        return n;
    if (n >= 2)
        return fibo_RR(n - 1) + fibo_RR(n - 2);
}

// Memoization or Top-Down approach = break down from big problem to small piece
// Theta(2n) => O(n)
int fibo_memo(int n)
{
    if (n == 0 || n == 1)
        return n;
    if (n >= 2)
    {
        if (table[n] > 0)
        {
            return table[n];
        }
        int value = fibo_memo(n - 1) + fibo_memo(n - 2);
        table[n] = value;
        return value;
    }
}

// Bottom-Up approach = build table constructively from smaller subproblems. Don't analyse in recursion aspect.
// O(n)
int fibo_bottomUp(int n)
{
    table[0] = 0;
    table[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table[n];
}
// Optimized Bottom-Up approach but using only 3 variables
int fibo_bottomUp_optimized(int n)
{
    if (n == 0 || n == 1)
        return n;
    int v1 = 0;
    int v2 = 1;
    int r = 0;
    for (int i = 2; i <= n; i++)
    {
        r = v1 + v2;
        v1 = v2;
        v2 = r;
    }
    return r;
}

int main(int argc, char const *argv[])
{
    cout << fibo_bottomUp_optimized(10);
    return 0;
}