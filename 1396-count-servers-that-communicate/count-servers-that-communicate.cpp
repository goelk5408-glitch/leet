class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int count=0;
        vector<int>row;
        vector<int>column;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    temp++;
                }
            }
            row.push_back(temp);
        }
        for(int j=0;j<n;j++){
            int temp=0;
            for(int i=0;i<m;i++){
                if(grid[i][j]==1){
                    temp++;
                }
            }
            column.push_back(temp);
        }
         for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 &&
                   (row[i] > 1 || column[j] > 1)) {
                    count++;
                }
            }
        }
        return count;

    }
};