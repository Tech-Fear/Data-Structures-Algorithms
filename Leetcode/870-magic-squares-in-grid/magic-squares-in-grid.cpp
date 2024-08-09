class Solution {
bool isSafe(vector<vector<int>>&grid,int r,int c){
    unordered_set<int>st;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int num=grid[r+i][c+j];
            if(num>9 || num<1 || st.count(num)){
                return false;
            }
            st.insert(num);
        }
    }
    int rSum=grid[r][c]+grid[r][c+1]+grid[r][c+2];
    for(int i=0;i<3;i++){
        if(grid[r+i][c]+grid[r+i][c+1]+grid[r+i][c+2]!=rSum) return false;
        if(grid[r][c+i]+grid[r+1][c+i]+grid[r+2][c+i]!=rSum) return false;
    }
    if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2]!=rSum) return false;
    if(grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c]!=rSum) return false;
    return true;
}
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        if(n<3 || m<3) return count;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                if(isSafe(grid,i,j)) count++;
            }
        }
        return count;
    }
};