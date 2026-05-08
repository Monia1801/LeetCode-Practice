class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        vector<bool> isPrime(mx + 1, true);
        if (mx >= 0) isPrime[0] = false;
        if (mx >= 1) isPrime[1] = false;

        for (int i = 2; i * i <= mx; i++) {
            if (isPrime[i]) {
                for (long long j = 1LL * i * i; j <= mx; j += i)
                    isPrime[j] = false;
            }
        }

        vector<vector<int>> pos(mx + 1);
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        vector<int> dist(n, -1);
        vector<bool> usedPrime(mx + 1, false);

        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1) return dist[i];

            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            int p = nums[i];

            if (p <= mx && isPrime[p] && !usedPrime[p]) {
                usedPrime[p] = true;

                for (int multiple = p; multiple <= mx; multiple += p) {
                    for (int idx : pos[multiple]) {
                        if (dist[idx] == -1) {
                            dist[idx] = dist[i] + 1;
                            q.push(idx);
                        }
                    }
                }
            }
        }

        return dist[n - 1];
    }
};