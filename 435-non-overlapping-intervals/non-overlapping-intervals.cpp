bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), compare);

        int count = 0;
       int lastEnd = INT_MIN;

        for(int i = 0; i < intervals.size(); i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start >= lastEnd) {
                count++;
                lastEnd = end;
            }
        }

        return intervals.size() - count;
    }
};