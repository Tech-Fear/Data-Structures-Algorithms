class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fr = n, fc = m;
        int er = -1, ec = -1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    if(i < fr) fr = i;
                    if(j < fc) fc = j;
                    if(i > er) er = i;
                    if(j > ec) ec = j;
                }
            }
        }
        if(fr == n || fc == m || er == -1 || ec == -1) return 0;
        return (er-fr+1)*(ec-fc+1);
    }
};
auto init=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return '$';
}();