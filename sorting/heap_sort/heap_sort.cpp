#include <iostream>
using namespace std;

void fix_down(vector<int> &v, int i, int size) {
    int tmp = v[i];
    int c;
    while (( c = 2 * i + 1 ) < size) {
        if (c + 1 <= size && v[c] < v[c+1]) c++;
        if (v[c] < tmp) break;
        v[i] = v[c];
        i = c;
    }
    v[i] = tmp;
}

//O(nlogn) build heap O(n) pop O(logn)
template<typename T>
void heap_sort(vector<T> &v) {
    for (size_t i = v.size()/2; i>=0; i--) {
        fix_down(v, i, v.size());
    }
    int pos = v.size() - 1;
    while (pos > 0) {
        swap(v[0], v[pos]);
        fix_down(v, 1, pos);
        pos--;
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
    for (auto &x: v) cout << x << " ";
    cout << endl;
    heap_sort(v);
    for (auto &x: v) cout << x << " ";
    return 0;
}
