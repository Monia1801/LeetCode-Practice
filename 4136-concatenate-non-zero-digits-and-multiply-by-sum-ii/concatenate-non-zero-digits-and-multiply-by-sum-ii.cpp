class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> pos, digit;

        // Store positions and values of non-zero digits
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        // powers of 10 modulo MOD
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // Prefix concatenated numbers and prefix digit sums
        vector<long long> prefNum(m + 1, 0), prefSum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digit[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            // First non-zero >= l
            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();

            // Last non-zero <= r
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long num = (prefNum[R + 1]
                            - prefNum[L] * pow10[len] % MOD
                            + MOD) % MOD;

            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};