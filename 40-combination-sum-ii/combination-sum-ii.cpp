class Solution {
    void solve(vector<int>&candidates,int target,int index,vector<vector<int>>&ans,vector<int>&temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int j=index;j<candidates.size();j++){
            if(j>index&&candidates[j]==candidates[j-1]){
                continue;
            }
            if (target-candidates[j]<0){
                break;
            }
              temp.push_back(candidates[j]);

            solve (candidates,target-candidates[j],j+1,ans,temp);
            temp.pop_back();

        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(candidates,target,0,ans,temp);
        return ans;
    }
};