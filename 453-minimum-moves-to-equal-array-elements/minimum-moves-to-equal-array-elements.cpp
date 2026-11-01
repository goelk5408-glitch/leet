class Solution {
public:
    int minMoves(vector<int>& nums) {
       int n=nums.size();
       int al=n-1;int count=0;
       sort(nums.begin(),nums.end());
       for(int i=n-1;i>=1;i--){
        if(nums[al]!=nums[al-1]){
            count=count+(nums[al]-nums[al-1])*(n-al);
        }
        al--;
       }
       return count;
    }
};