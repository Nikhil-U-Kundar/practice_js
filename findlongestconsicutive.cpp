#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestSequence(vector<int>& nums) {
    unordered_set<int> s;

    // Insert all elements into the set
    for (int i = 0; i < nums.size(); i++) {
        s.insert(nums[i]);
    }

    int ans = 0;

    // Iterate through the array to find the longest sequence
    for (int i = 0; i < nums.size(); i++) {
        // Check if nums[i] is the start of a sequence
        if (s.find(nums[i] - 1) != s.end()) {
            continue;
        } else {
            int count = 0;
            int current = nums[i];

            // Count the length of the sequence starting from current
            while (s.find(current) != s.end()) {
                count++;
                current++;
            }

            // Update the maximum sequence length found
            ans = max(ans, count);
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Length of the longest consecutive sequence: " << longestSequence(nums) << endl;
    return 0;
}
