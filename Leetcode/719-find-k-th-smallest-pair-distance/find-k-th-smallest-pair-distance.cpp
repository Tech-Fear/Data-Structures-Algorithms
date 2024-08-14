class Solution {
private:
    bool isValid(vector<int>&nums,int k,int n,int mid){
        int count=0;
        int left=0;
        for(int right=1;right<n;right++){
            while(nums[right]-nums[left]>mid){
                left++;
            }
            count+=(right-left);
        }
        return (count>=k);
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0,right=nums[n-1]-nums[0];
        while(left<right){
            int mid=left+(right-left)/2;
            if(isValid(nums,k,n,mid)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};