class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result = "";

        for (auto &word : words) {
            int sum = 0;

            for (char c : word) {
                sum += weights[c - 'a'];
            }

            int modVal = sum % 26;

            char mappedChar = 'z' - modVal;

            result.push_back(mappedChar);
        }

        return result;
    }
};