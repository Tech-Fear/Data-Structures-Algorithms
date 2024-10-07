class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        int naturalSum=0;
        if(n&1){
            naturalSum=n*((n+1)/2);
        }else{
            naturalSum=(n+1)*((n)/2);
        }
        return naturalSum-sum;
    }
};