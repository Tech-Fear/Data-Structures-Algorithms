//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void dfs(map<int,vector<int>>&adj,int s,vector<bool>&visited,vector<int>&ans){
        visited[s]=true;
        ans.push_back(s);
        for(auto &d:adj[s]){
            if(!visited[d]){
                dfs(adj,d,visited,ans);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        if(V==0) return {};
        map<int,vector<int>>adj1;
        for(int i=0;i<V;i++){
            for(auto &d:adj[i]){
                adj1[i].push_back(d);
                adj1[d].push_back(i);
            }
        }
        vector<int>ans;
        vector<bool>visited(V,false);
        dfs(adj1,0,visited,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends