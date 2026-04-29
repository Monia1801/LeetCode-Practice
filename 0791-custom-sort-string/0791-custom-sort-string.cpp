class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string result = "";
        for (char c : order) {
            while (freq[c - 'a']-- > 0) {
                result += c;
            }
        }
        for (int i = 0; i < 26; i++) {
            while (freq[i]-- > 0) {
                result += (char)(i + 'a');
            }
        }

        return result;
    }
};