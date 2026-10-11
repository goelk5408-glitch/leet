class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int element=nums[0];
           int count=1;
            for(int i=1;i<nums.size();i++){
          if (nums[i]==element&&count>0){
            count++;
          }
          else if ( nums[i]!=element&& count>0){
            count--;
            continue;
          }
          else if (count==0){
            element=nums[i];
            count=1;
            continue;
          }
        }

        int freq=0;
        for(int j=0;j<nums.size();j++)
        {
            if (nums[j]==element){
                freq++;
            }
            if(freq>nums.size()/2){
                return element;
            }
        }
        
   return -1; }
};