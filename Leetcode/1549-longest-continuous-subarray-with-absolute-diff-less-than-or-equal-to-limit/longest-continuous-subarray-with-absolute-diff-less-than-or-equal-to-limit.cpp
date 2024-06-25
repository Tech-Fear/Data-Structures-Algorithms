class Solution {
public: 
    typedef pair<int,int> P;
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<P,vector<P>>maxP;
        priority_queue<P,vector<P>,greater<P>>minP;
        int i=0,j=0;
        int maxLength=0;
        int n=nums.size();
        while(j<n){
            maxP.push({nums[j],j});
            minP.push({nums[j],j});
            while(maxP.top().first-minP.top().first>limit){
                i=min(maxP.top().second,minP.top().second)+1;
                while(maxP.top().second<i){
                    maxP.pop();
                }
                while(minP.top().second<i){
                    minP.pop();
                }
            }
            maxLength=max(maxLength,j-i+1);
            j++;
        }
        return maxLength;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return '$';
}();