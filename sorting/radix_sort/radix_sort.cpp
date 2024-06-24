#include <iostream>
#include <queue>
#define base 10
using namespace std;

int getDigit(int v, int k) {
    for(int i = 0; i < k; i++) v/= base;
    return v % base;
}
//O(n)
//d = number of digits
void radixSort(vector<int> &data, int d) {
    queue<int> q[base];
    for (int k = 0; k < d; k++) {
        for (auto &x : data) {
            q[getDigit(x, k)].push(x);
        }
        for (int i = 0, j = 0; i < base; i++) {
            while(!q[i].empty()) {
                data[j++] = q[i].front();
                q[i].pop();
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> v;
    v.push_back(15);
    v.push_back(1);
    v.push_back(167);
    v.push_back(6078);
    v.push_back(85);
    v.push_back(200);
    radixSort(v, 4);
    for (auto &x: v) cout << x << " ";
    return 0;
}
