class Solution {
private:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    void dfs(vector<vector<int>>&matrix,vector<vector<bool>>&ocean,int r,int c,int curr){
        if(r<0 || r>=matrix.size() || c<0 || c>=matrix[0].size()) return;
        if(matrix[r][c]<curr || ocean[r][c]) return;
        ocean[r][c]=true;
        for(int i=0;i<4;i++){
            dfs(matrix,ocean,r+dx[i],c+dy[i],matrix[r][c]);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<bool>>pacific(row,vector<bool>(col,false));
        vector<vector<bool>>atlantic(row,vector<bool>(col,false));

        /* First and last row */
        for(int c=0;c<col;c++){
            dfs(heights,pacific,0,c,INT_MIN);
            dfs(heights,atlantic,row-1,c,INT_MIN);
        }
        /* First and last col */
        for(int r=0;r<row;r++){
            dfs(heights,pacific,r,0,INT_MIN);
            dfs(heights,atlantic,r,col-1,INT_MIN);
        }
        /* Checking for water flow */
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(pacific[r][c] && atlantic[r][c]){
                    ans.push_back({r,c});
                }
            }
        }
        return ans;
    }
};