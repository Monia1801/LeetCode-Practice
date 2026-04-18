class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size(), ans = n + 1;
        unordered_map<int, int> pos;
        auto rev = [](int x) {
            int y = 0;
            while (x > 0) {
                y = y * 10 + x % 10;
                x /= 10;
            }
            return y;
        };
        for (int i = 0; i < n; i++) {
            if (pos.find(nums[i]) != pos.end())
                ans = min(ans, i - pos[nums[i]]);
            pos[rev(nums[i])] = i;
        }
        return ans > n ? -1 : ans;
    }
};