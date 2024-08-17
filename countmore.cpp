#include <iostream>
#include <unordered_map>
using namespace std;

int countOccurance(int arr[], int k, int n) {
    unordered_map<int, int> mp;
    int x = n / k, count = 0;

    for (int i = 0; i < n; i++) {
        mp[arr[i]] += 1;

        // Increment count when an element's frequency exceeds x
        if (mp[arr[i]] == x + 1) {
            count += 1;
        }
    }

    return count;
}

int main() {
    int arr[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    int result = countOccurance(arr, k, n);
    cout << "Number of elements that appear more than n/k times: " << result << endl;

    return 0;
}
