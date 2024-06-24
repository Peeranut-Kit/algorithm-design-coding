#include <iostream>
#include <map>
#include <queue>
using namespace std;

void showSolution(int value, map<int,int> m) {
    cout << value << " = 1 ";
    int prev;
    while((prev = m[value]) != -1) {
        if (prev * 3 == value) {
            cout << "* 3 ";
        }
        else {
            cout << "/ 2 ";
        }
        value = prev;
    }
}

void m3d2(int target) {
    map<int,int> prev;
    queue<int> q;
    int value = 1;
    q.push(1); prev[1] = -1;
    while (!q.empty()) {
        value = q.front(); 
        q.pop();
        if (value == target) break;
        int v2 = value/2;
        int v3 = value*3;
        if (prev[v2] == 0) {q.push(v2); prev[v2] = value;}
        if (prev[v3] == 0) {q.push(v3); prev[v3] = value;}
    }
    if (value == target) showSolution(value, prev);
}

int main(int argc, char const *argv[])
{
    m3d2(37);
    return 0;
}
