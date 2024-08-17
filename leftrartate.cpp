#include <iostream>
using namespace std;

// Function to rotate the array by one position to the left
void rotateByOne(int arr[], int n) {
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}

// Function to rotate the array to the left by k positions
void leftRotate(int arr[], int k, int n) {
    k = k % n; // In case k is greater than n
    for (int i = 0; i < k; i++) {
        rotateByOne(arr, n);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2; // Rotate by 2 positions
    
    leftRotate(arr, k, n);
    
    // Print the rotated array
    cout << "Array after rotation: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
