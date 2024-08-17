#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximizeDifference(vector<int>& arr, int n, int k) {
    // Sort the array
    sort(arr.begin(), arr.end());

    // Initial difference between the largest and smallest elements
    int ans = arr[n-1] - arr[0];

    int smallest = arr[0] - k;
    int largest = arr[n-1] + k;

    for (int i = 0; i < n - 1; i++) {
        int minElement = min(smallest, arr[i+1] + k);
        int maxElement = max(largest, arr[i] - k);

        // Skip if minElement is negative
        if (minElement < 0) continue;

        ans = max(ans, maxElement - minElement);
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 5, 8, 10};
    int k = 2;
    int n = arr.size();

    int result = maximizeDifference(arr, n, k);
    cout << "The maximum difference is: " << result << endl;

    return 0;
}
