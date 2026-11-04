class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        const long long INF = LLONG_MAX / 4;

        // coordinate compression
        vector<int> vals(nums.begin(), nums.end());
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int M = vals.size();
        vector<int> id(n);
        for (int i = 0; i < n; i++)
            id[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin() + 1;

        vector<int> cntB(M + 1, 0);
        vector<long long> sumB(M + 1, 0);
        auto upd = [&](int p, int c, long long v) {
            for (; p <= M; p += p & -p) { cntB[p] += c; sumB[p] += v; }
        };
        int LOG = 1;
        while ((LOG << 1) <= M) LOG <<= 1;
        int target = (x + 1) / 2;
        long long S = 0;

        vector<long long> cost(n - x + 1);
        for (int i = 0; i < n; i++) {
            upd(id[i], 1, nums[i]); S += nums[i];
            if (i >= x) { upd(id[i - x], -1, -nums[i - x]); S -= nums[i - x]; }
            if (i >= x - 1) {
                // target-th smallest dhundo (BIT descent)
                int pos = 0, rem = target, cl = 0;
                long long sl = 0;
                for (int pw = LOG; pw; pw >>= 1) {
                    if (pos + pw <= M && cntB[pos + pw] < rem) {
                        pos += pw;
                        rem -= cntB[pos];
                        cl += cntB[pos];
                        sl += sumB[pos];
                    }
                }
                long long m = vals[pos];   // median (pos+1 BIT index = vals[pos])
                // cl, sl = median se strictly chhote elements ka count, sum
                cost[i - x + 1] = (m * cl - sl) + ((S - sl) - m * (long long)(x - cl));
            }
        }

        // DP, rolling array
        vector<long long> prev(n + 1, 0), cur(n + 1, INF);
        for (int j = 1; j <= k; j++) {
            fill(cur.begin(), cur.end(), INF);
            for (int i = x; i <= n; i++) {
                cur[i] = cur[i - 1];
                if (prev[i - x] < INF)
                    cur[i] = min(cur[i], prev[i - x] + cost[i - x]);
            }
            swap(prev, cur);
        }
        return prev[n];
    }
};