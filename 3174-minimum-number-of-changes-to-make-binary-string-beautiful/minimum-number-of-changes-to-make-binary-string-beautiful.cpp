class Solution {
public:
    int minChanges(string s) {
        int i=0;
        int ans=0;
        while(i<s.length()-1){
            if(s[i]==s[i+1]){
                i=i+2;
                continue;
            }
            else{
                ans++;}
            i=i+2;
        }
        return ans;
    }
};