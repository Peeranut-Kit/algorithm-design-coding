#include <iostream>
#include <vector>
using namespace std;

// v0.1 pure brute force
void sum_of_subset01(int step, vector<bool> &used, vector<int> &D, int k) {
    if (step < D.size()) {
        used[step] = 0;
        sum_of_subset01(step+1, used, D, k);
        used[step] = 1;
        sum_of_subset01(step+1, used, D, k);
    }
    else {
        int sum = 0;
        for (int i = 0; i < D.size(); i++) {
            if (used[i]) sum += D[i];
        }
        if (sum == k) {
            for (int i = 0; i < D.size(); i++) {
                if (used[i]) cout << D[i] << " ";
            }
            cout << endl;
        }
    }
}

// v0.2 backtracking by delete exceed branch
void sum_of_subset02(int step, vector<bool> &used, vector<int> &D, int k, int total) {
    if (step < D.size()) {
        if (total > k) return; // This single line is backtracking.
        used[step] = 0;
        sum_of_subset02(step+1, used, D, k, total);
        used[step] = 1;
        sum_of_subset02(step+1, used, D, k, total + D[step]);
    }
    else {
        if (total == k) {
            for (int i = 0; i < D.size(); i++) {
                if (used[i]) cout << D[i] << " ";
            }
            cout << endl;
        }
    }
}

// v0.3 backtracking by delete over branch and insufficient branch
void sum_of_subset03(int step, vector<bool> &used, vector<int> &D, int k, int accum, int remaining) {
    if (step < D.size()) {
        if (accum > k) return; // This single line is backtracking.
        if (k - accum > remaining) return; // This line terminates branch that causes insufficient sum
        used[step] = 0;
        sum_of_subset03(step+1, used, D, k, accum, remaining - D[step]);
        used[step] = 1;
        sum_of_subset03(step+1, used, D, k, accum + D[step], remaining - D[step]);
    }
    else {
        if (accum == k) {
            for (int i = 0; i < D.size(); i++) {
                if (used[i]) cout << D[i] << " ";
            }
            cout << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector <int> D = {2,5,7,1,3,8};
    vector <bool> used(6);
    int k = 9;
    sum_of_subset03(0, used, D, k, 0, 26);
    return 0;
}