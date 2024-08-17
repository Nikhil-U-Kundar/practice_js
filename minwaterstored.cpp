#include <iostream>
#include <algorithm>  // For std::min and std::max
using namespace std;

int minimumWater(int height[], int n) {
    int l = 0;
    int r = n - 1;
    int maxWater = 0;

    while (l < r) {
        int lh = height[l];
        int rh = height[r];
        int minHeight = min(lh, rh);
        int len = r - l;
        int currentWater = minHeight * len;
        maxWater = max(maxWater, currentWater);

        if (lh < rh) {
            l++;
        } else {
            r--;
        }
    }
    return maxWater;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(height) / sizeof(height[0]);
    cout << "Maximum water that can be contained: " << minimumWater(height, n) << endl;
    return 0;
}
