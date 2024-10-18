class Solution {
public:
    void pourChamp(vector<vector<double>>& glasses, int i, int j) {
        if (glasses[i][j] > 1) {
            double extra = glasses[i][j] - 1;
            glasses[i][j] = 1;
            glasses[i + 1][j] += extra / 2.0;
            glasses[i + 1][j + 1] += extra / 2.0;
            pourChamp(glasses, i + 1, j);
            pourChamp(glasses, i, j + 1);
        }
    }
    double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> glass(101, vector<double>(101, 0.0));
    glass[0][0] = poured;
    
    for (int lev = 0; lev < query_row; lev++) {
        for (int j = 0; j <= lev; j++) {
            if (glass[lev][j] > 1) {
                double extra = glass[lev][j] - 1;
                glass[lev][j] = 1;
                glass[lev + 1][j] += extra / 2.0;
                glass[lev + 1][j + 1] += extra / 2.0;
            }
        }
    }
    
    return min(1.0, glass[query_row][query_glass]);
}
};