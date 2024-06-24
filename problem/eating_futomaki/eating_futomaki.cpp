#include <iostream>
#include <vector>
using namespace std;

int futomaki_score(vector<int> A, int n) {
    int score = 0;
    int left = 0, right = n - 1;
    while (left < right) {
        if (right-left >= 2) {
            int bigger_left = max(A[left], A[left+1]);
            int bigger_right = max(A[right], A[right-1]);
            if (bigger_left > bigger_right) {
                cout << bigger_left << " ";
                score += bigger_left;
                if (A[left] >= A[left+1]) {
                    if (A[left+1] > A[right])
                    {
                        left++;
                        right--;
                        cout << "1 ";
                    }
                    else {
                        left+=2;
                        cout << "2 ";
                    }
                }
                else {
                    left+=2;
                    cout << "3 ";
                }
            }
            else {
                score += bigger_right;
                cout << bigger_right << " ";
                if (A[right] >= A[right-1]) {
                    if (A[right-1] > A[left])
                    {
                        left++;
                        right--;
                        cout << "4 ";
                    }
                    else {
                        right-=2;
                        cout << "5 ";
                    }
                }
                else {
                    right-=2;
                    cout << "6 ";
                }
            }
        }
        else {
            score += max(A[left++], A[right--]);
            cout << max(A[left++], A[right--]) << " ";
            cout << "7 ";
        }
    }
    cout << endl;
    return score;
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