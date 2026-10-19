class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    int high=0;
    int low=1;
    for(int i=0;i<piles.size();i++){
    high=max(high,piles[i]);
    }
    while(low<=high){
        int mid=low+(high-low)/2;
       long long time=0;
        for(int i=0;i<piles.size();i++){
           if(piles[i]%mid==0){
            time+=piles[i]/mid;
           }
           else{
            time+=piles[i]/mid+1;
           }
        }
        
        
         if (time>h){
            low=mid+1;
        }
        else if(time<=h) {
            high=mid-1;
        }

    }return low;}
};