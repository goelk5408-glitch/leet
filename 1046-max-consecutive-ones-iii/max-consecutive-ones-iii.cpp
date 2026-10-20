class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0;
        int high=0;
        int maxi=0;
        int curr=0;
        int index=0;
        while(high<nums.size()){
            if(nums[high]==1){
                curr++;
                high++;
            }
           
            else if(nums[high]==0&&k>0){
                curr++;
                k--;
                
                high++;
            } 

            else if(nums[high]==0&&k<=0){
                  while (nums[low]!= 0) {
                    curr--;
                    low++;
                }
                curr--;
                low++;
                k++;
                continue;
            }

            maxi=max(maxi,curr);

        }
  return maxi;  }
};