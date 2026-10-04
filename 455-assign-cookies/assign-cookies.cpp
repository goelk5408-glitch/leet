class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());


    int low=0;
        int high=0;
        int content=0;
        while(high<s.size()&&low<g.size()){
            if (s[high]>=g[low]){
                content++;
                low++;
                high++;
            }
            else{
                high++;
            }
        }
    return content;}
};