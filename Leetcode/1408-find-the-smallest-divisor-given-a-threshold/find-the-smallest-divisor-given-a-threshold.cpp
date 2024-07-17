class Solution {
private:
    bool check(vector<int>&nums,int div,int thres){
        int sum=0;
        for(int num:nums){
            sum+=ceil(num/(double)div);
        }
        return sum<=thres;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long sum=0;
        int n=nums.size();
        int low=1,high=1e6,ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,mid,threshold)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'X';
}();