#include <vector>
#include <algorithm>


    int maxProduct(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int max_product = nums[0];
        int min_product = nums[0];
        int result = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                std::swap(max_product, min_product);
            }
            
            max_product = std::max(nums[i], max_product * nums[i]);
            min_product = std::min(nums[i], min_product * nums[i]);
            
            result = std::max(result, max_product);
        }
        
        return result;
    }
};
