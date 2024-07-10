class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int start=1;
        int n=nums.size();
        vector<int>pre(n),post(n);
        for(int i=0;i<n;i++){
            pre[i]=start;
            start*=nums[i];
        }
        int end=1;
        for(int i=n-1;i>=0;i--){
            post[i]=end;
            end*=nums[i];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=pre[i]*post[i];
        }
        return ans;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '$';
}();