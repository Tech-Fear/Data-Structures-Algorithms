//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
    private:
        void dfs(map<int,vector<int>>&adj,vector<bool>&visited,int &edg,int &vertices,int s){
            visited[s]=true;
            edg+=adj[s].size();
            for(auto &d:adj[s]){
                if(!visited[d]){
                    vertices++;
                    dfs(adj,visited,edg,vertices,d);
                }
            }
        }
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        int full=0;
        map<int,vector<int>>adj;
        for(auto &k:edges){
            int fir=k[0];
            int sec=k[1];
            adj[fir].push_back(sec);
            adj[sec].push_back(fir);
        }
        vector<bool>visited(v+1,false);
        for(int i=1;i<=v;i++){
            int edg=0;
            int vertices=1;
            if(!visited[i]){
                dfs(adj,visited,edg,vertices,i);
                if((vertices*(vertices-1))/2==edg/2) full++;
            }  
        }
        return full;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends