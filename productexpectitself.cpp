#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> left(n, 1);
    std::vector<int> right(n, 1);
    std::vector<int> result(n);

    // Calculate the left products
    for (int i = 1; i < n; ++i) {
        left[i] = left[i - 1] * nums[i - 1];
    }

    // Calculate the right products
    for (int i = n - 2; i >= 0; --i) {
        right[i] = right[i + 1] * nums[i + 1];
    }

    // Calculate the result by multiplying left and right products
    for (int i = 0; i < n; ++i) {
        result[i] = left[i] * right[i];
    }

    return result;
}
