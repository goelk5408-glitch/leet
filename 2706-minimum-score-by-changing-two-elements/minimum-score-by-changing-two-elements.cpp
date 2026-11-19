class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        int high=INT_MAX;
        sort(nums.begin(),nums.end());
        //change the first two with like the last one 
        high=min(high,nums[n-1]-nums[2]);
        high=min(high,nums[n-3]-nums[0]);
        high=min(high,nums[n-2]-nums[1]);
        return high;
    }
};