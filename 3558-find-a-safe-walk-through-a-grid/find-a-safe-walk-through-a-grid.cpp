class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int damage = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (damage > dist[r][c])
                continue;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;

                int nd = damage + grid[nr][nc];

                if (nd < dist[nr][nc]) {
                    dist[nr][nc] = nd;
                    pq.push({nd, nr, nc});
                }
            }
        }

        return dist[m - 1][n - 1] < health;
    }
};