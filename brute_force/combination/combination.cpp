#include <iostream>
#include <vector>
using namespace std;
//O(2^n)
void combi(int n, vector<int> &sol, int len) {
    if(len < n) {
        sol[len] = 0;
        combi(n, sol, len+1);
        sol[len] = 1;
        combi(n, sol, len+1);
    }
    else {
        for (int i = 0; i < n; i++) {
            if (sol[i] == 1) cout << i+1 << " ";
            //cout << sol[i] << " ";    => binary clock
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> sol(4);
    combi(4, sol, 0);
    return 0;
}
