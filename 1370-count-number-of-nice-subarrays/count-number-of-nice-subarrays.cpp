class Solution {
private:
    int atMost(vector<int>& nums, int k) {
        int l = 0, odd_count = 0, ans = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 != 0) {
                odd_count++;
            }

            while (odd_count > k) {
                if (nums[l] % 2 != 0) {
                    odd_count--;
                }
                l++;
            }

            ans += r - l + 1;
        }

        return ans;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};