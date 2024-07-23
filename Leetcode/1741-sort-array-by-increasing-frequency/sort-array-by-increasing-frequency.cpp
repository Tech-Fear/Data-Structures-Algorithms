class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        for(auto &m:nums){
            mp[m]++;
        }
        sort(nums.begin(),nums.end(),[&](int n1,int n2){
            if(mp[n1]!=mp[n2]){
                return mp[n1]<mp[n2];
            }else{
                return n1>n2;
            }
        });
        return nums;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return '#';
}();