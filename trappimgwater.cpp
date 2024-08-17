#include<iostream>
using namespace std;

long long trappingWater(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    int leftBar = arr[left];
    int rightBar = arr[right];
    long long ans = 0;

    while (left < right) {
        if (leftBar < rightBar) {
            left++;
            leftBar = max(leftBar, arr[left]);
            ans += leftBar - arr[left];
        } else {
            right--;
            rightBar = max(rightBar, arr[right]);
            ans += rightBar - arr[right];
        }
    }

    return ans;
}

int main() {
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Total water trapped: " << trappingWater(arr, n) << endl;
    return 0;
}
