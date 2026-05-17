class Solution {
public:

    bool check(long long mid, int k, long long n) {
        __int128 val = 1;

        for (int i = 0; i < k; i++) {
            val *= mid;

            if (val > n) {
                return false;
            }
        }

        return true;
    }

    long long kthRoot(long long n, int k) {
        if (n < 0) return -1;

        long long low = 0, high = n, ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (check(mid, k, n)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int countKthRoots(long long l, long long r, int k) {

        long long right = kthRoot(r, k) + 1;

        long long left = 0;

        if (l > 0) {
            left = kthRoot(l - 1, k) + 1;
        }

        return right - left;
    }
};