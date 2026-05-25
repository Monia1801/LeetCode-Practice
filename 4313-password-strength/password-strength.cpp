class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> low, up, digit, special;

        for(char c : password) {
            if(c >= 'a' && c <= 'z') low.insert(c);
            else if(c >= 'A' && c <= 'Z') up.insert(c);
            else if(c >= '0' && c <= '9') digit.insert(c);
            else if(c == '!' || c == '@' || c == '#' || c == '$')
                special.insert(c);
        }

        int score = 0;
        score += low.size() * 1;
        score += up.size() * 2;
        score += digit.size() * 3;
        score += special.size() * 5;

        return score;
    }
};