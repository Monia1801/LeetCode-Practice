class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;
        vector<int> dp(n + 1, INF);
        unordered_map<int, int> mp;
        mp[0] = 0;
        int prefix = 0;
        int ans = INF;
        for (int i = 1; i <= n; i++) {
            prefix += arr[i - 1];
            dp[i] = dp[i - 1];
            if (mp.count(prefix - target)) {
                int j = mp[prefix - target];
                int len = i - j;
                if (dp[j] != INF)
                    ans = min(ans, dp[j] + len);
                dp[i] = min(dp[i], len);
            }
            mp[prefix] = i;
        }
        return ans == INF ? -1 : ans;
    }
};