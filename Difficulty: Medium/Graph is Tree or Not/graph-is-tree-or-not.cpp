//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
    private:
        bool dfs(vector<vector<int>>& adjList, vector<bool>& visited, int node, int parent) {
            visited[node] = true;
            for (auto neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    if (!dfs(adjList, visited, neighbor, node)) {
                        return false;
                    }
                } else if (neighbor != parent) {
                    return false;
                }
            }
            return true;
        }

    public:
        int isTree(int n, int m, vector<vector<int>>& adj) {
            if (m != n - 1) return 0;

            vector<vector<int>> adjList(n);

            for (auto& edge : adj) {
                int u = edge[0];
                int v = edge[1];

                if (u == v) return 0;

                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }

            vector<bool> visited(n, false);

            if (!dfs(adjList, visited, 0, -1)) {
                return 0;
            }

            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    return 0;
                }
            }

            return 1;
        }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends