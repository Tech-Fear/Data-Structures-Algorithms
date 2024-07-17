class Solution {
    void dfs(unordered_map<int,vector<int>>&mp,int u,vector<bool>&visited){
        visited[u]=true;
        for(auto &v:mp[u]){
            if(!visited[v])
                dfs(mp,v,visited);
        }

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,vector<int>>mp;
        //adj list 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        //dfs 
        int count=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(mp,i,visited);
                count++;
            }
        }
        return count;
    }
};