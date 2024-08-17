#include<iostream>
using namespace std;

int main() {
    int arr[] = {4, 5, 8, 5, 8, 8, 8, 8, 5, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int currentMax = arr[0];  // Initialize to the first element
    int globalMax = arr[0];   // Global maximum to store the result

    for (int i = 1; i < n; i++) {
        currentMax = max(arr[i], currentMax + arr[i]);  // Calculate the maximum subarray ending at i
        globalMax = max(globalMax, currentMax);  // Update the global maximum if the current one is larger
    }

    cout << "Maximum sum of contiguous subarray is: " << globalMax << endl;

    return 0;
}
