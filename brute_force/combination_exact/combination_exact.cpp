#include <iostream>
#include <vector>
using namespace std;

void combi_exactK(int n, vector<int> &sol, int len, int k, int chosen) {
    if(len < n) {
        if (len - chosen < n - k) {
           sol[len] = 0;
            combi_exactK(n, sol, len+1, k, chosen); 
        }
        if (chosen < k) {
            chosen += 1;
            sol[len] = 1;
            combi_exactK(n, sol, len+1, k, chosen);
        }
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
    combi_exactK(4, sol, 0, 2, 0);
    return 0;
}
