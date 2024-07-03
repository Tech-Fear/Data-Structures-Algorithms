class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        int result=INT_MAX;
        if(n<=4) return 0;
        sort(nums.begin(),nums.end());
        result=min(result,nums[n-4]-nums[0]);
        result=min(result,nums[n-2]-nums[2]);
        result=min(result,nums[n-3]-nums[1]);
        result=min(result,nums[n-1]-nums[3]);
        return result;

    }
};
auto init=[](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();