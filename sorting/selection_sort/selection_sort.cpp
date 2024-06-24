#include <iostream>
using namespace std;
// Theta(n^2) 
// T(n) = n + n-1 + n-2 + ... + 2 = O(n) * O(n) at max_element
template<typename T>
void selection_sort(vector<T> &v) {
    for (size_t pos = v.size()-1; pos > 0; pos--)
    {
        auto it = max_element(v.begin(), v.begin()+pos+1);
        swap(v[pos], *it);
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
    selection_sort(v);
    for (auto &x: v) cout << x << " ";
    return 0;
}
