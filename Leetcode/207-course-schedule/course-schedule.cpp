class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        int count=0;
        queue<int>que;
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
             count++;
            for(int &v:adj[q]){
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                }
            }  
        }
        return count==numCourses;
    }
};