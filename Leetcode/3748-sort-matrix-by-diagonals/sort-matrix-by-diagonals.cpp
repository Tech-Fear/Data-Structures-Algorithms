class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& matrix) {
        map<int, vector<int>> diagonalMap;
        int rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                diagonalMap[i - j].push_back(matrix[i][j]);
            }
        }
        for (auto& entry : diagonalMap) {
            if (entry.first < 0) 
                sort(entry.second.begin(), entry.second.end());
            else 
                sort(entry.second.rbegin(), entry.second.rend());
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = diagonalMap[i - j].front();
                diagonalMap[i - j].erase(diagonalMap[i - j].begin());
            }
        }

        return matrix;
    }
};