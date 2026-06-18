class Solution {
public:
    bool consecutiveSetBits(int n) {
       bool found = false;
        int prev = 0;

        while (n > 0) {
            int cur = n & 1;

            if (prev == 1 && cur == 1) {
                if (found)
                    return false;    
                found = true;
            }

            prev = cur;
            n >>= 1;
        }

        return found; 
    }
};