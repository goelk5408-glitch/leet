//isme hum uske left small and right small nikalte hai then no of point to start the subarraya and end nikalke no of total subaraay k aajayege 
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        stack<int> st;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() &&
                   (i == n || arr[st.top()] >= arr[i])) {
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                long long count = 1LL * (mid - left) * (right - mid);
                ans = (ans + count * arr[mid]) % 1000000007;
            }

            if (i < n) st.push(i);
        }

        return ans;
    }
};