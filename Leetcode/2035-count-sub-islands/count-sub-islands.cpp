typedef vector<vector<int>> vv32;
class Solution {
private:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    bool isValid(vv32 &grid, int r, int c) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == 1;
    }
    void makeIslands(vv32 &grid,int r,int c,vector<pair<int,int>>&islandCell){
        if(!isValid(grid,r,c)) return;
        grid[r][c]=0;
        islandCell.push_back({r,c});
        for(int i=0;i<4;i++){
            int nr=dx[i]+r;
            int nc=dy[i]+c;
            if(isValid(grid,nr,nc)){
                makeIslands(grid,nr,nc,islandCell);
            }
        }
    }
    bool isSubIsland(vv32 &grid1,vector<pair<int,int>>&islandCell){
        for(auto &p:islandCell){
            int i=p.first;
            int j=p.second;
            if(grid1[i][j]==0) return false;
        }
        return true;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int count=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid2[r][c]==1){
                    vector<pair<int,int>> islandCell;
                    makeIslands(grid2,r,c,islandCell);
                    if(isSubIsland(grid1,islandCell)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};