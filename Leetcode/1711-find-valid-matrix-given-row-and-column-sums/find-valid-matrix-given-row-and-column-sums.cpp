class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rowSize=rowSum.size();
        int colSize=colSum.size();
        int i=0,j=0;
        vector<vector<int>>vec(rowSize,vector<int>(colSize,0));
        while(i<rowSize && j<colSize){
            int val=min(rowSum[i],colSum[j]);
            vec[i][j]=val;
            rowSum[i]-=val;
            colSum[j]-=val;
            if(rowSum[i]==0){
                i++;
            }
            if(colSum[j]==0){
                j++;
            }
        }
        return vec;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'E';
}();