class NumMatrix {
public:
    vector<vector<int>> pre;
    int n, m;

    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        pre.resize(n, vector<int>(m, 0));

        pre[0][0] = matrix[0][0];
        for (int i = 1; i < n; i++) {
            pre[i][0] = pre[i - 1][0] + matrix[i][0];
        }

        for (int i = 1; i < m; i++) {
            pre[0][i] = pre[0][i - 1] + matrix[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] +
                            matrix[i][j];
            }
        }
    }

    int sumRegion(int ur, int lc, int br, int rc) {
        int total = pre[br][rc];
        if (ur > 0) {
            total -= pre[ur - 1][rc];
        }
        if (lc > 0) {
            total -= pre[br][lc - 1];
        }
        if (ur > 0 && lc > 0) {
            total += pre[ur - 1][lc - 1];
        }
        return total;
    }
};