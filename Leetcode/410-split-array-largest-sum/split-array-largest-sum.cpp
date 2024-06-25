class Solution {
public:
    bool valid(vector<int>&nums,int k,long long mid){
        int count=0,sum=0;
        for(auto x:nums){
            if(x>mid) return false;
            if(x+sum>mid){
                count++;
                sum=x;
                if(count>=k) return false;
            }else{
                sum+=x;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int ans=-1;
        long long low=0,high=sum;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(valid(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};