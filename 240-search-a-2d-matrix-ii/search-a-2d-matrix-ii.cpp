class Solution{
public:
 bool searchMatrix(vector<vector<int>> &matrix, int target){
      int m=matrix.size()-1;
      int n=matrix[0].size()-1;
      int a=0;
     while((m-a)>=0&&n>=0){
        int start=matrix[a][n];
        if(start==target){
            return true;
        }
        if (start>target&&n>=0){
            n--;
        }
        else if(start<target&&a<=m){
            a++;
        }
        
     

     }

    return false;}
};