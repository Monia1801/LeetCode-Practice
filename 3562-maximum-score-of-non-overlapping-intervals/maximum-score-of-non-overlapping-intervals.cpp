class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<long long, 4>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }
        sort(a.begin(), a.end());
        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> res(
            n + 1,
            vector<vector<int>>(5)
        );
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i + 1][k];
                res[i][k] = res[i + 1][k];
                int lo = i + 1, hi = n;
                while (lo < hi) {
                    int mid = lo + (hi - lo) / 2;
                    if (a[mid][0] > a[i][1])
                        hi = mid;
                    else
                        lo = mid + 1;
                }
                int next = lo;
                long long takeScore = a[i][2] + dp[next][k - 1];
                vector<int> takeRes = res[next][k - 1];
                takeRes.push_back((int)a[i][3]);
                sort(takeRes.begin(), takeRes.end());
                if (takeScore > dp[i][k]) {
                    dp[i][k] = takeScore;
                    res[i][k] = takeRes;
                }
                else if (takeScore == dp[i][k] &&
                         takeRes < res[i][k]) {
                    res[i][k] = takeRes;
                }
            }
        }
        return res[0][4];
    }
};