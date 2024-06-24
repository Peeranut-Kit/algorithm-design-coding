#include <iostream>
using namespace std;

int table[11][11];

// Cn,r = n!/(r!(n-r)!) = ways to choose r things from n things
// Cn,r = Cn-1,r-1 + Cn-1,r
// Cn,r = 1     :   if r = 0 or n

// Recurrent Relation + D&C
// T(n) = T(n-1) + T(n-1) + O(1) => O(2^n)
int binomial_RR(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    return binomial_RR(n - 1, r - 1) + binomial_RR(n - 1, r);
}

// Memoization or Top-Down approach = break down from big problem to small piece
int binomial_memo(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    if (table[n][r] != 0)
    {
        return table[n][r];
    }
    int value = binomial_memo(n - 1, r - 1) + binomial_memo(n - 1, r);
    table[n][r] = value;
    return value;
}

// Bottom-Up approach = build table constructively from smaller subproblems. Don't analyse in recursion aspect.
// O(n*r)
int binomial_bottomUp(int n, int r)
{
    int counter = 0;
    for (size_t i = 0; i <= n; i++)
    {
        table[i][0] = 1;
        table[i][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            table[i][j] = table[i-1][j] + table[i-1][j-1];
            counter++;
            cout << counter << "." << i << " " << j << " = " << table[i][j] << endl;
        }
    }
    return table[n][r];
}

// Optimized Bottom-Up approach by filling only neccessary index
int binomial_bottomUp_optimized(int n, int r)
{
    int counter = 0;
    for (size_t i = 0; i <= n; i++)
    {
        table[i][0] = 1;
        table[i][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = max(r-(n-i),1); j <= min(i-1,r); j++) {
            table[i][j] = table[i-1][j] + table[i-1][j-1];
            counter++;
            cout << counter << "." << i << " " << j << " = " << table[i][j] << endl;
        }
    }
    return table[n][r];
}

int main(int argc, char const *argv[])
{
    cout << binomial_bottomUp(6, 3);
    return 0;
}