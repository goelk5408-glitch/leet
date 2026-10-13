
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the pivot from the right
        // Start from the second-last index
        int i = n - 2;

        // Move left while elements are in descending order
        while(i >= 0 && nums[i] >= nums[i+1]) {
            i--;
        }

        // Step 2: Find the next greater element than the pivot
        // Only execute if a valid pivot exists
        if(i >= 0) {
            int j = n - 1;

            // Search from the right for the first element
            // greater than the pivot
            while(nums[j] <= nums[i]) {
                j--;
            }

            // Step 3: Swap the pivot with that element
            swap(nums[i], nums[j]);
        }

        // Step 4: Reverse the suffix after the pivot
        // This makes the remaining elements ascending
        // If no pivot exists, reverse the entire array
        reverse(nums.begin() + i + 1, nums.end());
    }
};
