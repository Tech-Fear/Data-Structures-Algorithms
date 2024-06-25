class Solution {
public:
    int ans;
    bool isValid(vector<string>&board,int &row,int &col,int &n){
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void solve(vector<string>&board,int row,int &n){
        if(row==n){
            ans++;
            return;
        }
        for(int col=0;col<n;col++){
            if(isValid(board,row,col,n)){
                board[row][col]='Q';
                solve(board,row+1,n);
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        solve(board,0,n);
        return ans;
    }
};
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();