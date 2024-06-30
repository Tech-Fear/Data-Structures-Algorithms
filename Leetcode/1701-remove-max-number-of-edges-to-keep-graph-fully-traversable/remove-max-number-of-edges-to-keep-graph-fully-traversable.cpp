#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) : parent(n+1), rank(n+1, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unite(int u, int v) {
        int root_u = find(u), root_v = find(v);
        if (root_u == root_v) return false;
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsuAlice(n), dsuBob(n);
        int removedEdges = 0;
        int usedEdgesAlice = 0, usedEdgesBob = 0;

        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                bool aliceUnion = dsuAlice.unite(edge[1], edge[2]);
                bool bobUnion = dsuBob.unite(edge[1], edge[2]);
                if (!aliceUnion && !bobUnion) {
                    removedEdges++;
                } else {
                    if (aliceUnion) usedEdgesAlice++;
                    if (bobUnion) usedEdgesBob++;
                }
            }
        }

        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (dsuAlice.unite(edge[1], edge[2])) {
                    usedEdgesAlice++;
                } else {
                    removedEdges++;
                }
            }
        }

        for (const auto& edge : edges) {
            if (edge[0] == 2) {
                if (dsuBob.unite(edge[1], edge[2])) {
                    usedEdgesBob++;
                } else {
                    removedEdges++;
                }
            }
        }

        if (usedEdgesAlice == n-1 && usedEdgesBob == n-1) {
            return removedEdges;
        }
        return -1;
    }
}; 
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '#';
}();