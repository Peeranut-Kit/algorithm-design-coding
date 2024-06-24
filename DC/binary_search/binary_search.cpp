#include <iostream>
#include<vector>
using namespace std;

// T(n) = 2T(n/2) + O(1)
// O(log(n))
template<typename T>
int binary_search(vector<T> &v, T k, int start, int stop) {
    if (start == stop) return v[start] == k? start : -1;
    int m = (start+stop)/2;
    if (v[m] >= k) return binary_search(v, k, start, m);
    else return binary_search(v, k, m, stop);
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(6);
    v.push_back(28);
    cout << "k position is " << binary_search(v, 6, 0, v.size()-1);
    return 0;
}


