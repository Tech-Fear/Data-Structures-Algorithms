class Solution {
private:
    int dp[2][101][101];
    
    int solveForAlice(vector<int>& piles, int person, int index, int M) {
        if (index >= piles.size()) return 0;
        if (dp[person][index][M] != -1) return dp[person][index][M];
        
        int stones = 0;
        int result = (person == 1) ? -1 : INT_MAX;
        
        for (int x = 1; x <= min(2 * M, (int)piles.size() - index); x++) {
            stones += piles[index + x - 1];
            if (person == 1) {
                result = max(result, stones + solveForAlice(piles, 0, index + x, max(M, x)));
            } else {
                result = min(result, solveForAlice(piles, 1, index + x, max(M, x)));
            }
        }
        
        return dp[person][index][M] = result;
    }

public:
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solveForAlice(piles, 1, 0, 1);
    }
};
