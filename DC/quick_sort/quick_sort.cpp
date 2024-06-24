#include <iostream>
#include <vector>
using namespace std;

template<typename T>
int partition(T arr[], int start, int stop)
{
    T pivot = arr[start];
    
    int left = start + 1;
    int right = stop;
    while (left < right)
    {
        while (arr[left] <= pivot) left++;
        while (arr[right] > pivot) right--;
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
    swap(arr[start], arr[right]);
    return right;
}

// Quick Sort does not need large temporary space like Merge sort
// Worst case T(n) = T(n-1) + T(1) + O(n) => O(n^2)
// Best case T(n) = 2T(n/2) + O(n) => O(nlogn)
// Average case T(n) = n(ln(n)) + n => Theta(nlogn)
template<typename T>
void quickSort(T arr[], int start, int stop)
{
    // base case
    if (start < stop) {
        // partitioning the array
        int p = partition(arr, start, stop);
        // Sorting the left part
        quickSort(arr, start, p - 1);
        // Sorting the right part
        quickSort(arr, p + 1, stop);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {15, 1, 167, 6078, 85, 200, 130, -7, 9};
    for (auto &x: arr) cout << x << " ";
    cout << endl;
    quickSort(arr, 0, 8);
    for (auto &x: arr) cout << x << " ";
    return 0;
}