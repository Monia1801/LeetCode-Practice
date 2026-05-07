class Solution {
public:
    bool check(string s, string w) {
        int i = 0, j = 0;
        int n = s.size(), m = w.size();
        while (i < n && j < m) {
            if (s[i] != w[j]) return false;
            char ch = s[i];
            int cntS = 0, cntW = 0;
            while (i < n && s[i] == ch) {
                cntS++;
                i++;
            }
            while (j < m && w[j] == ch) {
                cntW++;
                j++;
            }
            if (cntS < cntW) return false;
            if (cntS != cntW && cntS < 3) return false;
        }
        return i == n && j == m;
    }

    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for (string w : words) {
            if (check(s, w)) ans++;
        }
        return ans;
    }
};