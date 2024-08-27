class Solution {
private:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    bool isValid(vector<vector<int>>&matrix,int r,int c){
        if(r<0 || r>=matrix.size()||c<0 || c>=matrix[0].size()) return false;
        return true;
    }
    int solve(vector<vector<int>>&matrix,int r,int c,vector<vector<int>>&memo){
        if(memo[r][c]!=-1) return memo[r][c];
        int maxLength=1;
        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(isValid(matrix,nr,nc)&& matrix[nr][nc]>matrix[r][c]){
                maxLength=max(maxLength,1+solve(matrix,nr,nc,memo));
            }
        }
        return memo[r][c]=maxLength;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxLength=0;
        vector<vector<int>>memo(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxLength=max(maxLength,solve(matrix,i,j,memo));
            }
        }
        return maxLength;
    }
};