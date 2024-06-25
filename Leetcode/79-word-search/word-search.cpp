class Solution {
public:
    bool helper(int i,int j,vector<vector<char>>&board,string word,int idx){
        int n=board.size(),m=board[0].size();
        if(word.length()==idx) return true;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='$') return false;
        if(board[i][j]!=word[idx]) return false;
        char temp=board[i][j];
        board[i][j]='$';
        if(helper(i-1,j,board,word,idx+1)|| helper(i,j-1,board,word,idx+1) || helper(i+1,j,board,word,idx+1)||helper(i,j+1,board,word,idx+1)) return true;
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && helper(i,j,board,word,0)) return true;
            }
        }
        return false;
    }
};