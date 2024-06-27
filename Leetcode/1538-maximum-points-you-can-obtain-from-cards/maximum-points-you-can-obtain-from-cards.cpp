class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum=0,rightSum=0,maxSum=0;
        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
        }
        int n=cardPoints.size();
        maxSum=leftSum;
        for(int i=0;i<k;i++){
            rightSum+=cardPoints[n-1-i];
            leftSum-=cardPoints[k-1-i];
            maxSum=max(maxSum,rightSum+leftSum);
        }
        return maxSum;
    }
};
auto init =[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'R';
}();