#include <iostream>
#include <vector>
using namespace std;

void celebrity(int B[][]) {
    int bi = start;
    int ci = m+1;
    for (int i = start; i <= stop; i++) {
        if (ci > stop) { tmp[i] = v[bi++]; continue; } // no more c, use b
        if (bi > m) { tmp[i] = v[ci++]; continue; } // no more b, use c
        tmp[i] = (v[bi] < v[ci]) ? v[bi++] : v[ci++];
    }
    for (int i = start; i <= stop; i++) v[i] = tmp[i];
} // O(n +n) = O(n)

//O(nlogn) but good on sort ที่ไม่ต้องข้ามตัวแปรไกลๆ ex sort link list in Python
template<typename T>
void merge_sort(vector<T> &v, int start, int stop, vector<T> &tmp) {
    if (start < stop) {
        int m = (start + stop) / 2;
        merge_sort(v, start, m, tmp);
        merge_sort(v, m+1, stop, tmp);
        merge(v, start, m, stop, tmp);
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
    v.push_back(130);
    v.push_back(-7);
    v.push_back(9);
    vector<int> tmp(9);
    for (auto &x: v) cout << x << " ";
    cout << endl;
    merge_sort(v, 0, v.size()-1, tmp);
    for (auto &x: v) cout << x << " ";
    return 0;
}