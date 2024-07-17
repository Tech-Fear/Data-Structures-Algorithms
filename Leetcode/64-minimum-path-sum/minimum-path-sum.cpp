class Solution{
private:
    int solve(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
      if(i>=n || j>=m) return INT_MAX;
      if(dp[i][j]!=-1) return dp[i][j];
      if(i==n-1 && j==m-1) return grid[i][j];
      int down=solve(i+1,j,n,m,grid,dp);
      int right=solve(i,j+1,n,m,grid,dp);
      return dp[i][j]=grid[i][j]+min(down,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,m,grid,dp);
    }
};