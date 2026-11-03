class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int l,r,length;
        int ans=1, start=0;
        for(int i=0;i<n;i++){
             // odd length, centered at i
             l=i-1;
             r=i+1;
             length=1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;r++;
                length=length+2;
            }
            if(length>ans){
                ans=length;
                start=l+1;
            }

             // even length, centered between i and i+1
             l=i;
             r=i+1;
             length=0;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;r++;
                length=length+2;
            }
            if(length>ans){
                ans=length;
                start=l+1;
            }
        }

        return s.substr(start,ans);
    }
};