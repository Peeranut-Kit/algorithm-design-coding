#include <iostream>
#include <vector>
using namespace std;

int three_max(int a, int b, int c) {
    return max(max(a,b),c);
}

//D&C final O(nlogn) 2T(n/2) + O(n)
int get_sum(vector<int> &S, int a, int b) {
    if (a == 0) {
        return S[b];
    }
    return S[b] - S[a-1]; //O(1)
}

int mss(vector<int> &v, int start, int stop, vector<int> &S) {
    if (start == stop) return v[start];
    int m = (start+stop)/2;

    int r1 = mss(v, start, m, S);
    int r2 = mss(v, m+1, stop, S);

    //find max of B[start...m][m]
    int max_sum_left = get_sum(S,m,m);
    for (size_t i = start; i < m; i++)
    {
        max_sum_left = max(max_sum_left, get_sum(S,i,m));
    }
    //find max of B[m+1...stop][stop]
    int max_sum_right = get_sum(S,m+1,stop);
    for (size_t j = m+2; j <= stop; j++)
    {
        max_sum_right = max(max_sum_right, get_sum(S,m+1,j));
    }
    int r3 = max_sum_left + max_sum_right;

    return three_max(r1,r2,r3);
}

int mss(vector<int> &v) {
    vector<int> S(v.size());
    S[0] = v[0];
    for (size_t i = 1; i < v.size(); i++)
    {
        S[i] = S[i-1] + v[i];
    }
    return mss(v,0,v.size()-1,S);
}

int main(int argc, char const *argv[])
{
    vector<int> v;
    v.push_back(3);
    v.push_back(-4);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(-1);
    v.push_back(5);
    v.push_back(-4);
    cout << kadane(v) << endl;
    return 0;
}
