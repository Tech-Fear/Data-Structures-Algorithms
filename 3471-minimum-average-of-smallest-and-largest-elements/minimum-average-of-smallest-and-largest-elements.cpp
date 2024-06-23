class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        double minAvg=999999;
        int i=0,j=nums.size()-1;
        while(i<j){
            double avg=(nums[i]+nums[j])/2.0;
            minAvg=min(avg,minAvg);
            i++;j--;
        }
        return minAvg;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return '$';
}();