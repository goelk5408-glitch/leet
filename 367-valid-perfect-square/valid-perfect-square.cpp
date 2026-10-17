class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num==1){
            return true;
        }
        int low=1;
        int high=num;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(mid*mid>num){
                high=mid-1;
            }
            else if(mid*mid<num){
                low=mid+1;
            }
           else if (mid*mid==num){
            return true;
        }
            
        }
        
  return false;  }
};