#include <iostream>
#include <vector>
using namespace std;

pair<int,int> array_mode_middle(vector<int> &v, int start, int stop) {
    if (v[start] == v[stop]) return make_pair(stop - start + 1, v[start]);
    int m = (start+stop)/2;

    pair<int,int> r1 = array_mode_middle(v, start, m);
    pair<int,int> r2 = array_mode_middle(v, m+1, stop);
    int r1f = r1.first;
    int r2f = r2.first;

    int i=m,j=m;
    while (i > start && v[i-1] == v[m]) i--;
    while (j < stop && v[j+1] == v[m]) j++;
    
    int r3f = j-i+1;
    
    if(r3f > r1f && r3f > r2f) {
        return make_pair(r3f, v[m]);
    }
    else if(r1f > r2f) return r1;
    else return r2;
}

pair<int,int> array_mode_crack(vector<int> &v, int start, int stop) {
    // if subarray all contains the same number
    if (v[start] == v[stop]) return make_pair(stop - start + 1, v[start]);

    int m = (start+stop)/2;
    if (v[m] == v[m+1])
    {
        int i=1,j=1;
        while (i < (m - start + 1) && v[m-i] == v[m]) i++;
        while (j < (stop - m + 1) && v[m+j] == v[m]) j++;
        i--; j--;
        if (i < j) m = m-i;
        else m = m+j;
    }

    pair<int,int> r1 = array_mode_crack(v, start, m);
    pair<int,int> r2 = array_mode_crack(v, m+1, stop);
    
    return (r1.first > r2.first)? r1 : r2;
}

pair<int,int> array_mode_leftcrack(vector<int> &v, int start, int stop) {
    // if subarray all contains the same number
    if (v[start] == v[stop]) return make_pair(stop - start + 1, v[start]);

    // find left crack
    int k = start;
    while ((k < stop) && (v[k+1] == v[start])) {
        k++;
    }

    pair<int,int> r1 = array_mode_leftcrack(v, start, k);
    pair<int,int> r2 = array_mode_leftcrack(v, k+1, stop);

    return (r1.first > r2.first)? r1 : r2;
}

pair<int,int> array_mode(vector<int> &v) {
    //return array_mode_middle(v,0,v.size()-1);
    //return array_mode_crack(v,0,v.size()-1);
    return array_mode_leftcrack(v,0,v.size()-1);
}

int main(int argc, char const *argv[])
{
    vector<int> sorted_array;

    // Add 1,000 instances of the number 1
    sorted_array.insert(sorted_array.end(), 1000, 1);

    // Add 1,500 instances of the number 2
    sorted_array.insert(sorted_array.end(), 1500, 2);

    // Add 2,000 instances of the number 3
    sorted_array.insert(sorted_array.end(), 2000, 3);

    // Add 5,000 instances of the number 4
    sorted_array.insert(sorted_array.end(), 5000, 4);

    // Add 6,000 instances of the number 5
    sorted_array.insert(sorted_array.end(), 6000, 5);

    pair<int,int> p = array_mode(sorted_array);
    cout << "value: " << p.second << ", frequency: " << p.first << endl;
    return 0;
}
