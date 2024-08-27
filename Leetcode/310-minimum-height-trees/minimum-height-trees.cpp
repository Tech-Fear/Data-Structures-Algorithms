class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        unordered_map<int,vector<int>>adjList;
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        queue<int>leaves;
        for(auto &m:adjList){
            if(m.second.size()==1)
                leaves.push(m.first);
        }
        while(n>2){
            int leavesCount=leaves.size();
            n-=leavesCount;
            for(int i=0;i<leavesCount;i++){
                int leaf=leaves.front(); leaves.pop();
                for(int &neigh:adjList[leaf]){
                    adjList[neigh].erase(remove(adjList[neigh].begin(),adjList[neigh].end(),leaf),adjList[neigh].end());
                    if(adjList[neigh].size()==1) leaves.push(neigh);
                }
            }
        }
        vector<int>ans;
        while(!leaves.empty()){
            ans.push_back(leaves.front());
            leaves.pop();
        }
        return ans;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'S';
}();