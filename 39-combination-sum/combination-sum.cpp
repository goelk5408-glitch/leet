class Solution {
    
    void solve(vector<int>& arr, int target, int index,vector<int>& temp, vector<vector<int>>& ans) {

        // Base case 1: If sum == target
        if (target==0){
            ans.push_back(temp);
            return;
        }
           
        // Base case 2: If index reaches array size
        if(target<0||index==arr.size()){
            return;
        }
        // Choice 1: Pick current element
        temp.push_back(arr[index]);
        solve(arr,target-arr[index],index,temp,ans);
        // Backtrack: remove last element from temp
        temp.pop_back();
        // Choice 2: Skip current element
        // Recursive call with index + 1
        solve(arr,target,index+1,temp,ans);

    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, target, 0, temp, ans);

        return ans;
    }
};