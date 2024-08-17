#include <iostream>
using namespace std;

void threeWayPartition(int arr[], int n, int a, int b) {
    int j = 0, k = n - 1;
    for (int i = 0; i <= k;) {
        if (arr[i] < a) {
            swap(arr[i], arr[j]);
            j++;
            i++;
        } else if (arr[i] > b) {
            swap(arr[i], arr[k]);
            k--;
        } else {
            i++;
        }
    }
}

int main() {
    int arr[] = {1, 4, 2, 10, 8, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int a = 3, b = 6;
    
    threeWayPartition(arr, n, a, b);
    
    cout << "Modified array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
