class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int minRow = min(startPos[0],homePos[0]);
        int maxRow = max(startPos[0],homePos[0]);
        int minCol = min(startPos[1],homePos[1]);
        int maxCol = max(startPos[1],homePos[1]);
        int cost=0;
        for (int i=minRow;i<=maxRow;i++) {
            cost += rowCosts[i];
        }
        cost -= rowCosts[startPos[0]];
        for (int i=minCol;i<=maxCol;i++) {
            cost += colCosts[i];
        }
        cost -= colCosts[startPos[1]];
        return cost;
    }
};