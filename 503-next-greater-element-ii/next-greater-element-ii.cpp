class Solution {
public:
    // Finds next greater values with a monotonic stack.
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> answer(n, -1);
        stack<int> candidates;

        // Scan right to left to prepare valid candidates.
        for (int i = 2*n - 1; i >= 0; i--) {
            int id=i%n;
            // Remove values failing the strict greater condition.
            while (!candidates.empty() && candidates.top() <= arr[id]) {
                candidates.pop();
            }

            // Use the nearest greater candidate at the stack top.
            if (i<n&&!candidates.empty()) {
                answer[id] = candidates.top();
            }

            candidates.push(arr[id]);
        }

        return answer;
    }
};