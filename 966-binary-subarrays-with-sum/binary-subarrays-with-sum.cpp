class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=nums.size();
        int i=0,j=0,count_zeros=0,sum=0;
        int result=0;
        while(j<n){
            sum+=nums[j];
            while(i<j && (nums[i]==0 || goal<sum)){
                if(nums[i]==0) count_zeros++;
                if(nums[i]==1) count_zeros=0;
                sum-=nums[i];
                i++;
            }
            if(goal==sum) result+=1+count_zeros;
            j++;
        }
        return result;
    }
};