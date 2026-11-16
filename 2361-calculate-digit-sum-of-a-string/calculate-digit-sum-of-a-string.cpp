class Solution {
public:
    string digitSum(string s, int k) {
        int n=s.length();
        
        while(n>k){
            string ans;
            int r=0;
            while(r<n){
                int sum=0;
                int i=0;
                while(i<k&&r<n){
                    sum+=s[r]-'0';
                    i++;
                    r++;
                }
                ans+=to_string(sum);

            }
            s=ans;
            n=s.length();

        }return s;
    }
};