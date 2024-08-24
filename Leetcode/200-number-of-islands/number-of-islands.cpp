class Solution {
private:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    void solve(vector<vector<char>>&grid,vector<vector<bool>>&visited,int r,int c){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || visited[r][c] || grid[r][c]=='0') return;
        visited[r][c]=true;
        for(int i=0;i<4;i++){
            solve(grid,visited,r+dx[i],c+dy[i]);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int row=grid.size(),col=grid[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(!visited[r][c] && grid[r][c]=='1'){
                    solve(grid,visited,r,c);
                    count++;
                }
            }
        }
        return count;
    }
};