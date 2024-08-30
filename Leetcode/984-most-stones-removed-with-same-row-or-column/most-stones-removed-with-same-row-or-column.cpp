class Solution {
public:
    vector<int> p, rank;
    int numSets;
    void init(int n) {
        p.resize(n);
        rank.resize(n, 0);
        numSets = n;
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }
    int findSet(int i) {
        if (p[i] != i) {
            p[i] = findSet(p[i]);
        }
        return p[i];
    }
    void unionSet(int i, int j) {
        int x = findSet(i);
        int y = findSet(j);
        if (x != y) {
            if (rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
                if (rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
            numSets--;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        init(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    unionSet(i, j);
                }
            }
        }
        return n - numSets;
    }
};