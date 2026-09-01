class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<vector<int>> id(m, vector<int>(n, -1));

        int sr, sc, cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        if (cnt == 0)
            return 0;

        int fullMask = (1 << cnt) - 1;

        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n, vector<int>(1 << cnt, -1))
        );

        queue<tuple<int, int, int, int>> q;

        q.push({sr, sc, energy, fullMask});
        best[sr][sc][fullMask] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                if (mask == 0)
                    return moves;

                if (e == 0)
                    continue;

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nm = mask;

                    if (classroom[nr][nc] == 'R')
                        ne = energy;

                    if (classroom[nr][nc] == 'L')
                        nm &= ~(1 << id[nr][nc]);

                    if (ne > best[nr][nc][nm]) {
                        best[nr][nc][nm] = ne;
                        q.push({nr, nc, ne, nm});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};