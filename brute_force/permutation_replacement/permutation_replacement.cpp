#include <iostream>
#include <vector>
using namespace std;
//O(n!)
void permu_Kreplacement(int n, vector<int> &sol, int len, int k) {
    if(len < k) {
        for (int i = 0; i < n; i++)
        {
            sol[len] = i+1;
            permu_Kreplacement(n, sol, len+1, k);
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
    permu_Kreplacement(4, sol, 0, 2);
    return 0;
}
