class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        int high=INT_MAX;
        sort(nums.begin(),nums.end());
        //change the first two with like the last one 
        high=min(min(nums[n-1]-nums[2],nums[n-3]-nums[0]),nums[n-2]-nums[1]);
        return high;
    }
};