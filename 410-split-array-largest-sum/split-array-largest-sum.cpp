class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int  n=nums.size();
        int high=0;
        int low=-1;
        for(int i=0;i<n;i++){
            low=max(low,nums[i]);
            high+=nums[i];
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int sam=0;
            int count=1;
            for (int i = 0; i < n; i++) {
            if (sam+ nums[i]<=mid) {
                sam+=nums[i];       
                } 
                 else {
              sam = nums[i];     
               count++;            
               }
}
            
            if(count>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    return low;}
};