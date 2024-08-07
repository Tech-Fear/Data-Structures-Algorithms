class Solution {
private:
    bool isSafe(int x,int y,int r,int c){
       return x>=0 && x<r && y<c && y>=0;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[]={1,1,1,0,0,-1,-1,-1};
        int dy[]={0,1,-1,1,-1,0,1,-1};
        int r=board.size();
        int c=board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int liveCounts=0;
                for(int k=0;k<8;k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (isSafe(ni, nj, r, c) && std::abs(board[ni][nj]) == 1) {
                        liveCounts++;
                    }
                }
                if(liveCounts==3 && board[i][j]==0) board[i][j]=2;
                else if(board[i][j]==1 && (liveCounts<2 || liveCounts>3)){
                    board[i][j]=-1;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                board[i][j]=board[i][j]>0?1:0;
            }
        }
    }
};