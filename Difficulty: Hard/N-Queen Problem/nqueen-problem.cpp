//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>>ans;
    bool isValid(vector<string>&board,int &n,int &row,int &col){
        //same row check 
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0 && j<n; i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void solve(vector<int>&cur,int &n,int row,vector<string>&board){
        if(row==n){
            ans.emplace_back(cur);
            return;
        }
        for(int col=0;col<n;col++){
            if(isValid(board,n,row,col)){
                cur.emplace_back(col+1);
                board[row][col]='Q';
                solve(cur,n,row+1,board);
                cur.pop_back();
                board[row][col]='.';
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        ans.clear();
        vector<int>cur;
        vector<string>board(n,string(n,'.'));
        solve(cur,n,0,board);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends