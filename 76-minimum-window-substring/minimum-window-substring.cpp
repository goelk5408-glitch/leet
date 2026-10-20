class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n<m){
            return"";
        }
         int hash[128]={0};
         for(char c:t){
            hash[c]++;
         }
         int l=0;
         int r=0;
         int count=0;
         int minlen=INT_MAX;
         int starting=-1;

         while(r<n){
            if(hash[s[r]]>0){
                count++;
            }hash[s[r]]--;
            while(count==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    starting=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    count--;
                }
                l++;

            }
            r++;

         }
         
  return starting==-1?"":s.substr(starting,minlen);  }
};