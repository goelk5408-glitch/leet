class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int temp1=0,temp2=0,ans=0;
        for (int i=1;i<nums.size();i++){
            if (nums[i]>nums[i-1]){
                temp2=0;
                temp1++;
            }
            else if (nums[i]<nums[i-1]){
                temp1=0;
                temp2++;
            }
            else if (nums[i]==nums[i-1]){
                temp1=0;
                temp2=0;
            }
            ans=max(ans,max(temp1,temp2));
        }return ans+1;
    }
};