class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
       long long init=min(costBoth,cost1+cost2);
       long long ans=0;
       if (need1<need2){
        ans+=init*need1;
        long long temp=min(costBoth,cost2);
        ans+=temp*(need2-need1);
       }
       else {
        ans+=init*need2;
        long long temp=min(costBoth,cost1);
        ans+=temp*(need1-need2);
       }
       return ans;
    }
};