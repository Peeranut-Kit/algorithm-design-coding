#include <iostream>
#include <vector>
using namespace std;

int futomaki_score(vector<int> &A, int n) {
    vector<vector <int> > dp(n, vector<int>(n, 0));
    vector<vector <int> > prefixSum(n, vector<int>(n, 0));

    // Fill prefixSum to store sums of subarrays
    for (int i = 0; i < n; ++i) {
        prefixSum[i][i] = A[i];
        for (int j = i + 1; j < n; ++j) {
            prefixSum[i][j] = prefixSum[i][j - 1] + A[j];
        }
    }

    for (int length = 2; length <= n; ++length) {
        for (int l = 0; l + length - 1 < n; ++l) {
            int r = l + length - 1;
            // Consider all possible cuts and maximize deliciousness for A
            if (length >= 2) {
                // Two pieces from the left
                dp[l][r] = max(dp[l][r], max(A[l], A[l + 1]) + (prefixSum[l + 2][r] - dp[l + 2][r]));
                // Two pieces from the right
                dp[l][r] = max(dp[l][r], max(A[r], A[r - 1]) + (prefixSum[l][r - 2] - dp[l][r - 2]));
            }
            if (length >= 3) {
                // One piece from each side
                dp[l][r] = max(dp[l][r], max(A[l], A[r]) + (prefixSum[l + 1][r - 1] - dp[l + 1][r - 1]));
            }
        }
    }

    return dp[0][n - 1];
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
    cout << futomaki_score(A,n) << endl;
    return 0;
}