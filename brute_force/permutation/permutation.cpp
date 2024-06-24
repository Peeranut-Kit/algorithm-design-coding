#include <iostream>
#include <vector>
using namespace std;
//O(n!)
void permu_KfromN(int n, vector<int> &sol, vector<bool> &used, int len, int k) {
    if(len < k) {
        for (int i = 0; i < n; i++)
        {
            if (used[i] == false) {
                used[i] = true;
                sol[len] = i+1;
                permu_KfromN(n, sol, used, len+1, k);
                used[i] = false;
            }
        }
    }
    else {
        //for (auto &x: sol) cout << x;
        for (size_t i = 0; i < k; i++)
        {
            cout << sol[i];
        }
        
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> sol(4);
    vector<bool> used(4);
    permu_KfromN(4, sol, used, 0, 2);
    return 0;
}
