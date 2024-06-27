#include <iostream>
#include <vector>
using namespace std;

int futomaki_score(vector<int> A, int n) {
    int score = 0;
    int left = 0, right = n - 1;
    while (left < right) {
        if (right-left >= 2) {
            int smaller_left = max(A[left], A[left+1]);
            int smaller_right = max(A[right], A[right-1]);
            if (smaller_left < smaller_right) {
                if (A[left] >= A[left+1]) {
                    score += A[left];
                    left += 2;
                }
                else {
                    if (A[left+1] > A[right])
                    {
                        score += A[left+1];
                        left += 2;
                    }
                    else {
                        score += A[right];
                        left++;
                        right--;
                    }
                }
            }
            else {
                if (A[right] >= A[right-1]) {
                    score += A[right];
                    right -= 2;
                }
                else {
                    if (A[right-1] > A[left])
                    {
                        score += A[right-1];
                        right -= 2;
                    }
                    else {
                        score += A[left];
                        left++;
                        right--;
                    }
                }
            }
            /*int bigger_left = max(A[left], A[left+1]);
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
            }*/
        }
        else {
            score += max(A[left++], A[right--]);
            /*cout << max(A[left++], A[right--]) << " ";
            cout << "7 ";*/
        }
    }
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