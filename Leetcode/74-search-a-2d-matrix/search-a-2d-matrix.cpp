class Solution {
public:
    int binarySearchCol(vector<vector<int>>& matrix, int target,int &row){
        int m=matrix[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[row][mid]==target) return mid;
            if(matrix[row][mid]>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
    int binarySearchRow(vector<vector<int>>& matrix, int target){
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid][0]<=target && matrix[mid][m-1]>=target){
                return mid;
            }else if(matrix[mid][0]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=binarySearchRow(matrix,target);
        if(row==-1) return false;
        int col=binarySearchCol(matrix,target,row);
        if(col==-1) return false;
        return true;

    }
};
auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '@';
}();