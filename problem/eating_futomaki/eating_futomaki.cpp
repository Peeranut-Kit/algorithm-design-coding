#include <iostream>
#include <vector>
using namespace std;

int futomaki_score(vector<vector<int>> &dp, vector<int> &A, int n, int start, int stop)
{
    if (start > stop) return 0;
    if (dp[start][stop] != 0) return dp[start][stop];

    int r1 = futomaki_score(dp, A, n, start + 2, stop) + max(A[start], A[start + 1]);
    int r2 = futomaki_score(dp, A, n, start + 1, stop - 1) + max(A[start], A[stop]);
    int r3 = futomaki_score(dp, A, n, start, stop - 2) + max(A[stop], A[stop - 1]);

    dp[start][stop] = max(max(r1, r2), r3);
    return dp[start][stop];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vector<vector<int>> dp(n);
    for (size_t i = 0; i < n; i++)
    {
        vector<int> tmp(n);
        dp[i] = tmp;
    }
    cout << futomaki_score(dp, A, n, 0, n - 1) << endl;
    return 0;
}
