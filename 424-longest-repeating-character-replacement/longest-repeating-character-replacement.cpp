class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26]={0};
        for(int i=0;i<s.length();i++){
            hash[s[i]-'A']++;
        }int final=0;
        for(int i=0;i<26;i++){
            int maxi=0;
            if (hash[i]>0){
                int low=0;
                int high=0;
                int curr=0;
                
                int changes =k;
                while(high<s.length()){
                    if (s[high]=='A'+i){
                        curr++;
                        high++;
                    }
                    else if(s[high]!='A'+i&&changes>0){
                        curr++;
                        changes--;
                        high++;
                    }
                    else {
                          if (s[low] != 'A' + i) {
                        curr--;
                        low++;
                        changes++;
                    }
                    else {
                        curr--;
                        low++;
                    }
                    continue;
                    }
                    maxi=max(maxi,curr);
                }
                
            }
       final=max(final,maxi); }


  return final;  }
};