#include <iostream>
#include <vector>
using namespace std;

int p[3] = {2, 20, 11};
int w[3] = {3, 4, 5};
int W = 7;

// ver. brute force combination + backtracking
void knapsack_brute(int step, vector<bool> &sol, int sumP, int sumW, int &max_value) {
    if (sumW > W) return; // This line is backtracking
    if (step < sol.size()) {
        sol[step] = 0;
        knapsack_brute(step+1, sol, sumP, sumW, max_value);
        sol[step] = 1;
        knapsack_brute(step+1, sol, sumP + p[step], sumW + w[step], max_value);
    }
    else {
        if (sumP > max_value && sumW <= W) { max_value = sumP; }
    }
}

// ver. backtracking + bounding heuristic
void knapsack_BB(int step, vector<bool> &sol, int sumP, int sumW, int &max_value, int tail[]) {
    if (sumW > W) return; // This line is backtracking
    if (tail[step] + sumP < max_value) return; // This line is bounding heuristic.
    if (step < sol.size()) {
        sol[step] = 1; // We try to went maximum max_value as fast as possible to minimize the branch we have to do by heuristic.
        knapsack_BB(step+1, sol, sumP + p[step], sumW + w[step], max_value, tail);
        sol[step] = 0;
        knapsack_BB(step+1, sol, sumP, sumW, max_value, tail);
    }
    else {
        if (sumP > max_value && sumW <= W) { max_value = sumP; }
    }
}

void knapsack_BB(int &max_value) {
    vector <bool> sol(3);
    // tail[] = sum of element since i to end
    int tail[3];
    tail[2] = p[2];
    for (int i = 1; i >= 0; i--) tail[i] = tail[i+1] + p[i];
    knapsack_BB(0, sol, 0, 0, max_value, tail);
}

int main(int argc, char const *argv[])
{
    vector <bool> sol(3);
    int max_value = -1;
    knapsack_brute(0, sol, 0, 0, max_value);
    cout << max_value;
    return 0;
}