class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<vector<int>>ans;
        if(nums.size()<3) return ans;
        for(int i=0;i<nums.size()-2;i++){
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                long long sum=nums[i]+nums[l]+nums[r];
                if(sum==0){
                    st.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }else if(sum<0){
                    l++;
                }else{
                    r--;
                }
            }
        }
        for(auto &i:st){
            ans.push_back(i);
        }
        return ans;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return '$';
}();