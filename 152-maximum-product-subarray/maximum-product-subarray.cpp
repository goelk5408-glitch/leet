class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long prefix = 1, suffix = 1;
        long long ans = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            if (prefix == 0) prefix = 1;      // restart after a zero
            if (suffix == 0) suffix = 1;

            prefix *= nums[i];                // left to right
            suffix *= nums[n - 1 - i];        // right to left

            ans = max(ans, max(prefix, suffix));
        }
        return (int)ans;
    }
};