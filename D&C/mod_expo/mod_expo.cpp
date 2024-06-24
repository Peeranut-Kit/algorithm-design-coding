#include <iostream>
using namespace std;

//T(n/2) + O(1) -> O(logn)
int mod_expo(int a, int n, int k) {
    if (n==1) return a % k;
    int temp = mod_expo(a,n/2,k);
    if (n%2 == 0)   return (temp * temp) % k;
    else    return ((temp * temp % k) * (a % k)) % k;
}

int main(int argc, char const *argv[])
{
    int x = mod_expo(2, 349587187, 10);
    cout << x << endl;
    return 0;
}
