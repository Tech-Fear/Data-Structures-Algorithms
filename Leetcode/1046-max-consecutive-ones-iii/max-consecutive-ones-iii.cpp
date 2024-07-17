class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0;
        int countZero=0;
        int maxConsOne=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) countZero++;
            while(countZero>k){
                if(nums[start]==0){
                    countZero--;
                }
                start++;
            }
            maxConsOne=max(maxConsOne,i-start+1);
        }
        return maxConsOne;
    }
};