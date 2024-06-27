#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print_chess(vector<T> &cell) {
    for (size_t i = 0; i < cell.size(); i++)
        {
            cout << cell[i] << " ";
        }
        cout << endl;
}

void check(vector<bool> &cell) {
    // check whether there are 8 queens and cannot capture each other
}

void check2(vector<int> &col) {
    // check whether there are not more than 1 queen in the same column and cannot capture each other
}

void check3(vector<int> &col) {
    // check whether there are no queen that can capture each other
}

// v0.1 basic 64-bit binary counter from normal brute force
void e_queen01(int step, vector<bool> &cell, int chosen) {
    if (step < 64) {
        if (step - chosen < 64 - 8) {
            cell[step] = false;
            e_queen01(step+1, cell, chosen);
        }
        if (chosen < 8) {
            cell[step] = true;
            e_queen01(step+1, cell, chosen+1);
        }
    }
    else {
        check(cell);
    }
}

// v0.2 only 1 queen will be placed in a row
void e_queen02(int step, vector<int> &col) {
    if (step < 8) {
        for (int i = 0; i < 8; i++) {
            col[step] = i;
            e_queen02(step+1, col);
        }
    }
    else {
        check2(col);
    }
}

// v0.3 only 1 queen will be placed in a row and a column
void e_queen03(int step, vector<int> &col, vector<bool> &used) {
    if (step < 8) {
        for (int i = 0; i < 8; i++) {
            if (!used[i]) {
                used[i] = true;
                col[step] = i;
                e_queen03(step+1, col, used);
                used[i] = false;
            }
        }
    }
    else {
        check3(col);
    }
}

// v0.4 permutation by combination
void permu(int step, vector<int> &v) {
    if (step < v.size()) {
        for (size_t i = 0; i < v.size(); i++)
        {
            v[step] = i;
            permu(step+1, v);
        }
    } else {
        check2(v);
    }
}

int main(int argc, char const *argv[])
{
    vector <bool> cell(64);
    vector <int> col(8);
    vector <bool> used(8);
    e_queen03(0, col, used);
    return 0;
}
