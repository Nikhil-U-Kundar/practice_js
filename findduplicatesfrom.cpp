#include <iostream>
using namespace std;

void findDuplicateElements(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Corrected the inner loop
            if (arr[i] == arr[j]) {
                cout << arr[i] << " "; // Print the duplicate element
                break; // This will prevent printing the same duplicate multiple times
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    findDuplicateElements(arr, n);
    return 0;
}
