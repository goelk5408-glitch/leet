class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
       int min_sum=INT_MAX;
       for(int size=l;size<=r;size++){ 
        int initial=0;
        for(int i=0;i<size;i++){
            initial+=nums[i];
        }
        int a=0,b=size;
        while(a+b<=nums.size()){
            if(initial>0){
                min_sum=min(min_sum,initial);
            }
            
            initial-=nums[a];
            a++;

             if (a+b<=nums.size()) {
                    initial+=nums[a+size-1];
                }

        }
        
        } if(min_sum==INT_MAX){
            return -1;
        }
        else {
            return min_sum;
        }
        
    }
};