class Solution {

    int sum=0;
    void sort(vector<int>&arr,int low,int high){
        if(low>=high){
            return;
        }
       int  mid=(low+high)/2;
        sort(arr,low,mid);
        sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    void merge(vector<int>&arr,int low,int mid,int high){

        vector<int> temp;
        int left=low;
        int right=mid+1;
         //to count the reverse pairs separately;
        for (int left = low; left <= mid; left++) {
            while (right <= high &&
                   (long long)arr[left] > 2LL * arr[right]) {
                right++;
            }
            sum += right - (mid + 1);}
            right=mid+1;


        while (left<=mid&&right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;

            }
            else{
                
                temp.push_back(arr[right]);
                right++;
            }}
            while(left<=mid){
                temp.push_back(arr[left]);
                left++;
            }
            while(right<=high){
                temp.push_back(arr[right]);
                right++;
            }
            for(int i=low;i<=high;i++){
                arr[i]=temp[i-low];

            }
        
    }
public:
    int reversePairs(vector<int>& nums) {
        sum=0;
      sort(nums,0,nums.size()-1);
    return sum;}
};