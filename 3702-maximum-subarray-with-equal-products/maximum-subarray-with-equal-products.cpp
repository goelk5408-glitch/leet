class Solution {
public:
    int maxLength(std::vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;
        
        // 1. Calculate the maximum theoretical product to prune unnecessary inner loops
        int global_max_element = 0;
        long long global_lcm = 1;
        for (int x : nums) {
            global_max_element = std::max(global_max_element, x);
            global_lcm = std::lcm(global_lcm, (long long)x);
        }
        long long max_allowed_product = global_lcm * global_max_element;

        // 2. Iterate through all possible subarrays (i to j)
        for (int i = 0; i < n; ++i) {
            long long running_prod = 1;
            long long running_lcm = 1;
            long long running_gcd = 0; // GCD of first element x and 0 is x
            
            for (int j = i; j < n; ++j) {
                running_prod *= nums[j];
                
                // Early check: if product exceeds theoretical limit, any further extension is invalid
                if (running_prod > max_allowed_product) {
                    break;
                }
                
                running_gcd = std::gcd(running_gcd, (long long)nums[j]);
                running_lcm = std::lcm(running_lcm, (long long)nums[j]);
                
                // Check if the condition satisfies
                if (running_prod == (running_lcm * running_gcd)) {
                    max_len = std::max(max_len, j - i + 1);
                }
            }
        }
        
        return max_len;
    }
};
