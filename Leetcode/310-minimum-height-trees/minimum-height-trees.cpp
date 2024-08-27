class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        unordered_map<int,vector<int>>adjList;
        queue<int>que;
        for(auto &v:edges){
            int f=v[0];
            int s=v[1];
            adjList[f].push_back(s);
            adjList[s].push_back(f);
        }
        for(int i=0;i<n;i++){
            if(adjList[i].size()==1){
                que.push(i);
            }
        }
        while(n>2){
            int leavesCount=que.size();
            n-=leavesCount;
            for(int i=0;i<leavesCount;i++){
                int leaf=que.front();que.pop();
                for(int &neigh:adjList[leaf]){
                     adjList[neigh].erase(remove(adjList[neigh].begin(), adjList[neigh].end(), leaf), adjList[neigh].end());
                    if(adjList[neigh].size()==1){
                        que.push(neigh);
                    }
                }
            }
        }
        vector<int>ans;
        while(!que.empty()){
            ans.push_back(que.front());
            que.pop();
        }
        return ans;
    }
};