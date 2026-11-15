class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd=0;
        int even=0;
         long long  sum=0;
        int r=0;
        while(r<arr.size()){
            if (arr[r]%2!=0){
                 odd=even+1;
                 even=r+1-odd;
                sum+=odd;
            }
            else{
                even=even+1;
                odd=r+1-even;
                sum+=odd;
            }
            r++;

        }
        return sum%1000000007;
    }
};