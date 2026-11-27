class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                ++digits[i];
                return digits;
            }

            digits[i] = 0;  // Carry 1 to the next digit on the left.
        }

        // Every digit was 9, so we need a new leading 1.
        digits.insert(digits.begin(), 1);
        return digits;
    }
};