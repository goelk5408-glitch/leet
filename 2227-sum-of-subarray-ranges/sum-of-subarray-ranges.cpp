
class Solution {
        long long sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // left[i] = index of previous strictly smaller, else -1
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // right[i] = index of next smaller-or-equal, else n
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long count = (long long)(i - left[i]) * (right[i] - i);
            ans = (ans + arr[i] * count) ;
        }
        return ans;
    }

        long long sumSubarrayMax(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // left[i] = index of previous strictly smaller, else -1
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // right[i] = index of next smaller-or-equal, else n
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <=arr[i]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long count = (long long)(i - left[i]) * (right[i] - i);
            ans = (ans + arr[i] * count);
        }
        return ans;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums)-sumSubarrayMins(nums);
    }
};