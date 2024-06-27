#include <iostream>
#include <map>
#include <queue>
using namespace std;

void BFS_triple_and_half(int goal) {
    queue<int> q;
    map<int,int> prev;
    q.push(1); prev[1] = -1;
    while(!q.empty()) {
        int value = q.front();
        q.pop();
        if (value == goal) break;
        int v2 = value/2;
        int v3 = value*3;
        if (prev.find(v2) == prev.end()) {
            q.push(v2);
            prev[v2] = value;
        }
        if (prev.find(v3) == prev.end()) {
            q.push(v3);
            prev[v3] = value;
        }
    }

    int original = goal;
    string text = "";
    while ( prev[goal] != -1) {
        int value_prev = prev[goal];
        if (value_prev * 3 == goal) {
            text = " * 3" + text;
        }
        else {
            text = " / 2" + text;
        }
        goal = value_prev;
    }
    cout << "1" << text << " = " << original;
}

int main(int argc, char const *argv[])
{
    BFS_triple_and_half(13);
    return 0;
}
