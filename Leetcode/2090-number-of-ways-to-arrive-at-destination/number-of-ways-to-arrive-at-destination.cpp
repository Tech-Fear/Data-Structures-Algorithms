class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD=1e9+7;
        vector<int>ways(n,0);
        vector<long long>times(n,LLONG_MAX);
        unordered_map<int,vector<pair<int,long long>>>mp;
        for(auto &road:roads){
            int u=road[0];
            int v=road[1];
            int t=road[2];
            mp[u].push_back({v,t});
            mp[v].push_back({u,t});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
        pq.push({0,0});
        ways[0]=1;
        while(!pq.empty()){
            pair<long long,int>temp=pq.top();
            pq.pop();
            long long old_time=temp.first;
            int u=temp.second;
            for (auto &m : mp[u]) {
                int v = m.first;
                int time = m.second;
                long long new_time = old_time + time;

                if (new_time < times[v]) {
                    times[v] = new_time;
                    ways[v] = ways[u];
                    pq.push({new_time, v});
                } else if (new_time == times[v]) {
                    ways[v] = (ways[v]+ ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};