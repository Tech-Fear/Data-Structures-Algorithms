class Solution {
private: 
    void dfs(int sv,vector<bool>&visited,vector<vector<int>>&adj){
        visited[sv]=true;
        for(int i=0;i<adj[sv].size();i++){
            if(visited[adj[sv][i]]) continue;
            dfs(adj[sv][i],visited,adj);
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<vector<int>>res(n);
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        for(int i=0;i<n;i++){
            vector<bool>visited(n,false);
            dfs(i,visited,adj);
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(visited[j]) res[j].push_back(i);
            }
        }
        return res;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '#';
}();