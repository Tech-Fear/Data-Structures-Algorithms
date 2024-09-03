class Solution {
public:
    const int MOD = 1e9 + 7;
    int dfs(vector<vector<int>>& temp, vector<int>& size, int root) {
        int ans = 1;
        for (auto& t : temp[root]) {
            ans += dfs(temp, size, t);
        }
        size[root] = ans;
        return ans;
    }
    int MMI(int denom, int M) { return power(denom, M - 2); }
    int power(int a, int b) {
        if (b == 0)
            return 1;
        long long half = power(a, b / 2);
        long long res = (half * half) % MOD;
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        return res;
    }
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        vector<vector<int>> temp(n);
        for (int i = 1; i < n; i++) {
            temp[prevRoom[i]].push_back(i);
        }
        vector<int> size(n);
        dfs(temp, size, 0);
        long long denom = 1;
        for (int s : size) {
            denom = (denom * s) % MOD;
        }
        long long nFact = 1;
        for (int i = 2; i <= n; i++) {
            nFact = (nFact * i) % MOD;
        }
        long long inverse = MMI(denom, MOD);
        long long ans = (nFact * inverse) % MOD;
        return (int)ans;
    }
};
