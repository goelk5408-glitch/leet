class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        long long total=0;
        for(int i=0;i<cardPoints.size();i++){
            total+=cardPoints[i];
        }
        if(k == cardPoints.size())
           return total;
        int low=0;
        int high=cardPoints.size()-k;
        long long minsum=0;
        for(int i=0;i<high;i++){
            minsum+=cardPoints[i];
        }
        long long final=minsum;
        long long newm=0;

        while(high<cardPoints.size()){
            newm=minsum-cardPoints[low]+cardPoints[high];
            minsum=newm;
            final=min(final,minsum);
            high++;
            low++;
        }
        long long ans=total-final;
    return ans; }
};