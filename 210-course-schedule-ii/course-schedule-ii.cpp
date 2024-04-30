class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        queue<int>que;
        vector<int>result;
        int count=0;
        unordered_map<int,vector<int>>adj;
        for(auto &v:prerequisites){
            int a=v[0];
            int b=v[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int q=que.front();
            que.pop();
            result.push_back(q);
            count++;
            for(int &v:adj[q]){
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                }
            }
        }
        if(count==numCourses){
            return result;
        }
        return {};
    }
};