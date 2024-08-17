#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void sumOfPairEqualToK(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int complement = k - arr[i];
        if (mp.find(complement) != mp.end()) {
            cout << "Pair found: (" << complement << ", " << arr[i] << ")" << endl;
        }
        mp[arr[i]] = i;
    }
}

int main() {
    vector<int> arr = {1, 5, 7, -1, 5};
    int k = 6;

    sumOfPairEqualToK(arr, k);

    return 0;
}
