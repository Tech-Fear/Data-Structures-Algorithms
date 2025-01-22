class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater[0].size();
        int inf = rows + cols;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (isWater[r][c] == 1)
                    isWater[r][c] = 0;
                else
                    isWater[r][c] = 1;
            }
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (isWater[r][c] == 0)
                    continue;
                int left = inf, top = inf;
                if (c - 1 >= 0)
                    left = isWater[r][c - 1];
                if (r - 1 >= 0)
                    top = isWater[r - 1][c];
                isWater[r][c] = min(left, top) + 1;
            }
        }
        for (int r = rows - 1; r >= 0; r--) {
            for (int c = cols - 1; c >= 0; c--) {
                if (isWater[r][c] == 0)
                    continue;
                int right = inf, bottom = inf;
                if (r + 1 < rows)
                    bottom = isWater[r + 1][c];
                if (c + 1 < cols)
                    right = isWater[r][c + 1];
                isWater[r][c] = min(isWater[r][c], min(right, bottom) + 1);
            }
        }

        return isWater;
    }
};
