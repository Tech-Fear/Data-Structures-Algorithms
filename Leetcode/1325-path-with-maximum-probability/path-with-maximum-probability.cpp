class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        unordered_map<int, vector<pair<int, double>>> adjList;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double succ = succProb[i];
            adjList[u].push_back({v, succ});
            adjList[v].push_back({u, succ});
        }
        priority_queue<pair<double, int>> pq;
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;
        pq.push({1.0, start_node});
        while (!pq.empty()) {
            double currentProb = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (node == end_node)
                return currentProb;
            for (auto &neighbor : adjList[node]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;
                double newProb = currentProb * edgeProb;

                if (newProb > maxProb[nextNode]) {
                    maxProb[nextNode] = newProb;
                    pq.push({newProb, nextNode});
                }
            }
        }

        return 0.0;
    }
};