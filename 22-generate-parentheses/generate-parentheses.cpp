class Solution {
    vector<string>ans;
    void sol(string s,int open,int close,int n){
        
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        
      if(open < n) {
    s.push_back('(');
    sol(s, open+1, close, n);
    s.pop_back();  // Undo the opening bracket
}

if(close < open) {
    s.push_back(')');
    sol(s, open, close+1, n);
    s.pop_back();  // Undo the closing bracket
}
    }
public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
       sol("",0,0,n);
       return ans;
        
    }
};