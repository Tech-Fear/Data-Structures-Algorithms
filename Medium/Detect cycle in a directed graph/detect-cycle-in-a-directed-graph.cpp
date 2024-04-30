//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int count=0;
        queue<int>que;
        vector<int>indegree(V,0);
        //Finding the indegree of each node
        for(int i=0;i<V;i++){
            for(int &v:adj[i]){
                indegree[v]++;
            }
        }
        //Pushing element with indegree 0 to queue
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }
        //bfs
        while(!que.empty()){
            int q=que.front();
            count++;
            que.pop();
            for(int &v:adj[q]){
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                }
            }
        }
        if(count==V){
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends