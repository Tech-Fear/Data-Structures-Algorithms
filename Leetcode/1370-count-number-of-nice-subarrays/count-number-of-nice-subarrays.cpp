class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        int i=0,j=0,count_zeros=0,sum=0;
        int result=0;
        while(j<n){
            sum+=nums[j];
            while(i<j &&(nums[i]==0 || sum>k)){
                sum-=nums[i];
                if(nums[i]==0) count_zeros++;
                if(nums[i]==1) count_zeros=0;
                i++;
            }
            if(k==sum) result+=1+count_zeros;
            j++;
        }
        return result;
    }
};