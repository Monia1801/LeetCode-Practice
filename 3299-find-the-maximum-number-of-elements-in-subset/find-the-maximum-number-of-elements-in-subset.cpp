class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;

        for (int x : nums)
            cnt[x]++;

        int ans = 0;

        // Handle 1 separately
        if (cnt.count(1)) {
            ans = cnt[1];
            if (ans % 2 == 0) ans--;
        }

        cnt.erase(1);

        for (auto &[v, _] : cnt) {
            long long x = v;
            int t = 0;

            while (cnt.count(x) && cnt[x] > 1) {
                t += 2;

                // prevent overflow before squaring
                if (x > 1000000000LL) break;

                x *= x;
            }

            if (cnt.count(x))
                t++;
            else
                t--;

            ans = max(ans, t);
        }

        return ans;
    }
};