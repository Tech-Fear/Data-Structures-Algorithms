class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long val=nums[n-1];
        long long res=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>val){
            long long p=ceil(nums[i]/(double)val);
            res+=(p-1);
            val=nums[i]/p;
            }else{
                val=nums[i];
            }
        }
        return res;
    }
};