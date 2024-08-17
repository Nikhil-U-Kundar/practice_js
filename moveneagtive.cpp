#include <iostream>
#include <vector>
using namespace std;

void sortArrayNegativeFirstFollowedByPositive(vector<int>& arr, int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        // Move the left pointer forward if the current element is negative
        while (arr[left] < 0 && left < right) {
            left++;
        }

        // Move the right pointer backward if the current element is positive
        while (arr[right] >= 0 && left < right) {
            right--;
        }

        // Swap the left positive and right negative elements
        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    vector<int> arr = {-5, 5, 6, 8, 8, -2, -4};
    int n = arr.size();

    sortArrayNegativeFirstFollowedByPositive(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
