class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int count = 0;
        int n=nums.size();
        int flipsOfindex=0;
        for(int i=0;i<n;i++){
            if(i>=k && nums[i-k]==2){
                flipsOfindex--;
            }
            if(flipsOfindex%2==nums[i]){
                if(i+k>n) return -1;
                flipsOfindex++;
                nums[i]=2;
                count++;
            }
        }
        return count;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return '$';
}();