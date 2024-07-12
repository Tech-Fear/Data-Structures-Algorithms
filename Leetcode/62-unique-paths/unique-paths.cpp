typedef long long ll;
class Solution {
private:
    ll uniquePathsHelper(ll i,ll j,vector<vector<int>> &grid,ll m,ll n){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if (grid[i][j] != -1) return grid[i][j];
            grid[i][j] = uniquePathsHelper(i + 1, j, grid, m, n) + uniquePathsHelper(i, j + 1, grid, m, n);
        return grid[i][j];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m,vector<int>(n,-1));
        return uniquePathsHelper(0,0,grid,m,n);
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '$';
}();