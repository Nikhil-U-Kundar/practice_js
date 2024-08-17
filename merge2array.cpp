#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> mergeAndSortArrays(int arr1[], int arr2[], int n, int m) {
    set<int> s;  // Using set to store unique elements
    vector<int> ans;  // To store the final sorted array without duplicates

    // Insert elements from the first array into the set
    for (int i = 0; i < n; i++) {
        s.insert(arr1[i]);
    }

    // Insert elements from the second array into the set
    for (int i = 0; i < m; i++) {
        s.insert(arr2[i]);
    }

    // Transfer elements from the set to the vector
    for (auto it : s) {
        ans.push_back(it);
    }

    return ans;  // Return the merged and sorted vector
}

int main() {
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 3, 5, 6, 8};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    vector<int> result = mergeAndSortArrays(arr1, arr2, n, m);

    // Print the sorted merged array
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
