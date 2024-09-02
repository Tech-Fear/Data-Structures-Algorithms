class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps,l,r=0;
        jumps=l=r;
        while(r<nums.size()-1){
            int furthest=0;
            for(int i=l;i<=r;i++){
                furthest=max(furthest,i+nums[i]);
            }
            l=r+1;
            r=furthest;
            jumps++;
        }
        return jumps;
    }
};