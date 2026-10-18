class Solution {
    //base case
    vector<vector<int>>mergesort(vector<int>&nums,int low,int high){
      if(low==high){
        return{{},{nums[low]}};
      }
      // two mein split kara
      int mid=low+(high-low)/2;
      vector<vector<int>>left=mergesort(nums,low,mid);
      vector<vector<int>>right=mergesort(nums,mid+1,high);

      //combination lagake subaaray banaye
      vector<vector<int>>ans;
      for(auto& left:left){
        for(auto&right:right){
            vector<int>temp=left;
            for(int x:right){
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
      }


  return ans;  }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int low=0;
        int n=nums.size();
        int high=n-1;
       return mergesort(nums,low,high);

        
    }
};