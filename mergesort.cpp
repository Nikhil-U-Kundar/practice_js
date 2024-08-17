#include <iostream>
#include <vector>
using namespace std;

int mergeAndCount(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    
    // Temporary arrays
    int a[n1], b[n2];
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        a[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        b[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = l;
    int inv_count = 0;

    // Merge the two halves and count inversions
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k++] = a[i++];
        } else {
            arr[k++] = b[j++];
            inv_count += (n1 - i); // Elements remaining in a[] are inversions
        }
    }

    // Copy remaining elements of a[]
    while (i < n1)
        arr[k++] = a[i++];

    // Copy remaining elements of b[]
    while (j < n2)
        arr[k++] = b[j++];

    return inv_count;
}

int mergeSortAndCount(int arr[], int l, int r) {
    int inv_count = 0;
    if (l < r) {
        int mid = l + (r - l) / 2;

        inv_count += mergeSortAndCount(arr, l, mid);
        inv_count += mergeSortAndCount(arr, mid + 1, r);

        inv_count += mergeAndCount(arr, l, mid, r);
    }
    return inv_count;
}

int main() {
    int arr[] = {2, 4, 1, 23, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int inversion_count = mergeSortAndCount(arr, 0, n - 1);

    cout << "Number of inversions: " << inversion_count << endl;

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
