#include <iostream>
#include <vector>
using namespace std;
//O(n^2)
template<typename T>
void insertion_sort(vector<T> &v) {
    for (int pos = v.size() -2; pos >= 0; pos--)
    {
        T tmp = v[pos];
        size_t i = pos + 1;
        while (i < v.size() && v[i] < tmp) {
            v[i-1] = v[i];
            i++;
        }
        v[i-1] = tmp;
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
    insertion_sort(v);
    for (auto &x: v) cout << x << " ";
    return 0;
}
