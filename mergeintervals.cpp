#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    // Sort the intervals based on the start time
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> ans;
    
    for (int i = 0; i < intervals.size(); i++) {
        if (ans.empty()) {
            // If the answer vector is empty, add the current interval
            ans.push_back(intervals[i]);
        } else {
            // Get reference to the last interval in the answer vector
            vector<int>& v = ans.back();
            int y = v[1]; // The end time of the last interval
            
            // Check if the current interval overlaps with the last interval
            if (intervals[i][0] <= y) {
                // Merge the intervals by updating the end time of the last interval
                v[1] = max(y, intervals[i][1]);
            } else {
                // If there's no overlap, add the current interval to the answer vector
                ans.push_back(intervals[i]);
            }
        }
    }
    
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> merged = mergeIntervals(intervals);

    cout << "Merged Intervals: " << endl;
    for (const auto& interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
