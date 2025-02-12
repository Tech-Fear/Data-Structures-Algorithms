class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> adj;
    vector<int> fees;
    vector<vector<int>> dp;
    int findCost(int n, int maxTime) {
        if (maxTime < 0)
            return -1;
        if (dp[n][maxTime] != -1)
            return dp[n][maxTime] == INT_MAX ? -1 : dp[n][maxTime];
        if (n == 0)
            return fees[0];
        int cost = INT_MAX;
        for (auto& p : adj[n]) {
            int co = findCost(p.first, maxTime - p.second);
            if (co != -1 ) {
                if(co==INT_MAX)
                cost=min(cost,co);
                else
                cost = min(cost, fees[n] + co);
            }
        }
        dp[n][maxTime] = cost;
        return dp[n][maxTime];
    }
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {
        dp = vector<vector<int>>(1001, vector<int>(1001, -1));
        fees = move(passingFees);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        int ans=findCost(fees.size() - 1, maxTime);
        if(ans==2147483647) return -1;
        return ans;
    }
};