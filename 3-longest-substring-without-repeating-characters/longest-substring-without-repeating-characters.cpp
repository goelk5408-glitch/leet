class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       if(s==""){
        return 0;
       }
        unordered_set<char>st;
        int low=0;
        int high=1;
        int maxi=1;
        int curr=1;
        st.insert(s[0]);
        while(high<s.length()){
            if(st.find(s[high])==st.end()){
                 st.insert(s[high]);
                 curr++;
                high++;
               
         }  maxi=max(curr,maxi);

             if(st.find(s[high])!=st.end()){
              st.erase(s[low]);
              low++;
              curr--;
            }
            
        }
    
return maxi;}};