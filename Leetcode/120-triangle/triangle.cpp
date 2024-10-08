class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        // vector<vector<int>>ans(n+1,vector<int>(n+1,0));
        // for(int i=n-1;i>=0;i--){
        //     for(int j=0;j<=i;j++){
        //         ans[i][j]=triangle[i][j]+min(ans[i+1][j],ans[i+1][j+1]);
        //     }
        // }
        // return ans[0][0];
        vector<vector<int>>ans=triangle;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                ans[i][j]=triangle[i][j] + min(ans[i + 1][j], ans[i + 1][j + 1]);
            }
        }
        return ans[0][0];
    }
};