//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<vector<char>>paths;
    void solve(int i,int j,vector<vector<int>>&m,int &n,vector<char>&cur){
        if(i<0 || i>=n || j>=n || j<0 || m[i][j]==0) return;
        if(i==n-1 && j==n-1){
            paths.push_back(cur);
            return;
        }
        m[i][j]=0;
        cur.push_back('L');
        solve(i,j-1,m,n,cur);
        cur.pop_back();

        cur.push_back('R');
        solve(i,j+1,m,n,cur);
        cur.pop_back();

        cur.push_back('U');
        solve(i-1,j,m,n,cur);
        cur.pop_back();

        cur.push_back('D');
        solve(i+1,j,m,n,cur);
        cur.pop_back();
        
        m[i][j]=1;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<char>cur;
        solve(0,0,m,n,cur);
        vector<string>ans;
        for(auto &v:paths){
            string st="";
            for(auto &i:v){
                st+=i;
            }
            ans.push_back(st);
        }
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends