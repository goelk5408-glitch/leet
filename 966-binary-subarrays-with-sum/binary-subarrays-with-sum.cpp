class Solution {
    private:
    int ans(vector<int>&arr,int a){
        if (a<0){
            return 0;
        }
        int sum=0,l=0 ,r=0,count=0;
        for(int r=0;r<arr.size();r++){
            sum+=arr[r];
            while(sum>a){
                sum-=arr[l];
                l++;
            }
            count+=r-l+1;

        }
  return count;  }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return ans(nums,goal)-ans(nums,goal-1);
    }
};