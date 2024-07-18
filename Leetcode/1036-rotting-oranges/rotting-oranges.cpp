class Solution {
private:
    bool isValid(int i, int j, vector<vector<bool>>& visited, int n, int m) {
        return i < n && j < m && i >= 0 && j >= 0 && !visited[i][j];
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    que.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int count = -1;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while (!que.empty()) {
            ++count;
            int size = que.size();
            while (size--) {
                pair<int, int> p = que.front();
                que.pop();
                for (int i = 0; i < 4; ++i) {
                    int x = p.first + dx[i];
                    int y = p.second + dy[i];
                    if (isValid(x, y, visited, n, m) && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        que.push({x, y});
                        visited[x][y] = true;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return count == -1 ? 0 : count;
    }
};
