class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rowStart = 0, rowEnd = matrix.size() - 1;
        int colStart = 0, colEnd = matrix[0].size() - 1;
        while (rowStart <= rowEnd && colStart <= colEnd) {
            for (int i = colStart; i <= colEnd; i++) {
                ans.push_back(matrix[rowStart][i]);
            }
            rowStart += 1;
            for (int i = rowStart; i <= rowEnd; i++) {
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd -= 1;
            if(rowStart<=rowEnd){
            for (int i = colEnd; i >= colStart; i--) {
                ans.push_back(matrix[rowEnd][i]);
            }
            rowEnd -= 1;
            }
            if (colStart<= colEnd) {
                for (int i = rowEnd; i >= rowStart; i--) {
                    ans.push_back(matrix[i][colStart]);
                }
                colStart += 1;
            }
        }
        return ans;
    }
};
auto it=[](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'x';
}();