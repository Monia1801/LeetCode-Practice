class Solution {
public:
    string helper(int n) {
        vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
            "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen","Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen","Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty",
            "Sixty", "Seventy", "Eighty", "Ninety"};
        if (n < 20) return ones[n];
        if (n < 100) return tens[n / 10] + (n % 10 ? " " + helper(n % 10) : "");
        return ones[n / 100] + " Hundred" + (n % 100 ? " " + helper(n % 100) : "");
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        vector<pair<int, string>> units = { {1000000000, "Billion"}, {1000000, "Million"},
            {1000, "Thousand"}
        };
        string ans = "";
        for (auto &[value, name] : units) {
            if (num >= value) {
                ans += helper(num / value) + " " + name;
                num %= value;
                if (num) ans += " ";
            }
        }
        if (num) ans += helper(num);
        return ans;
    }
};