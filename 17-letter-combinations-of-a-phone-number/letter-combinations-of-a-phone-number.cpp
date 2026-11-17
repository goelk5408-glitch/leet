class Solution {
     unordered_map<int,string>mp={
        {2,"abc"},
        {3,"def"},
        {4,"ghi"},
        {5,"jkl"},
        {6,"mno"},
        {7,"pqrs"},
        {8,"tuv"},
        {9,"wxyz"}
        };
    void solve(string&a,vector<string>&ans,string temp,int index){
    if(index==a.length()){
            ans.push_back(temp);
            return;
        }
    
     string letters=mp[a[index]-'0'];
     for(int i=0;i<letters.length();i++){
        solve(a,ans,temp+letters[i],index+1);
     }

    };

public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string temp;
        if (digits.empty())return ans;
        solve(digits,ans,temp,0);
        return ans;
    }
};