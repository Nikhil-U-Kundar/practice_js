#include <iostream>
using namespace std;

int medianOfTwoSortedArrays(int arr1[], int arr2[], int n) {
    int i = 0, j = 0;  // Pointers for arr1 and arr2
    int m1 = -1, m2 = -1;  // To store the two medians

    for (int count = 0; count <= n; count++) {
        // If all elements of arr1 are smaller than the current element of arr2
        if (i == n) {
            m1 = m2;
            m2 = arr2[0];
            break;
        }

        // If all elements of arr2 are smaller than the current element of arr1
        if (j == n) {
            m1 = m2;
            m2 = arr1[0];
            break;
        }

        if (arr1[i] <= arr2[j]) {
            m1 = m2;  // Store the previous median
            m2 = arr1[i];
            i++;
        } else {
            m1 = m2;  // Store the previous median
            m2 = arr2[j];
            j++;
        }
    }

    // Return the average of the two medians
  if( ((m1 + m2) / 2)%2==0){
return (m1+m2)/2;
  }else{
    return((m1+m2)/2)-1;
  }
}

int main() {
    int arr1[] = {1, 12, 15, 26, 38};
    int arr2[] = {2, 13, 17, 30, 45};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    
    cout << "Median of the two sorted arrays: " << medianOfTwoSortedArrays(arr1, arr2, n) << endl;

    return 0;
}
