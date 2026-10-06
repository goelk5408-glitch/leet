class Solution {
public:
     vector<int>merge( vector<int>a,vector<int>b){
            int x=min(a[0],b[0]);
            int y=max(a[1],b[1]);
            return {x,y};}
            

             bool islap(vector<int>a,vector<int>b){
          int  max1=max(a[0],b[0]);
           int min1=min(a[1],b[1]);
            if (max1>min1){
                return false;
            }
            else return true;
            }

            vector<vector<int>> merge(vector<vector<int>>& intervals) {
                sort(intervals.begin(),intervals.end());

            
            vector<vector<int>>result;
            result.push_back(intervals[0]);
            
        for (int i = 1; i < intervals.size(); i++) {
            if (islap(result.back(), intervals[i])) {
                result.back() = merge(result.back(), intervals[i]);
            } else {
                result.push_back(intervals[i]);
            }
        }



        return result; }
    };