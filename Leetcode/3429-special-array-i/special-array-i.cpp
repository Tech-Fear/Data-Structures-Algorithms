class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return true;
        }
        for(int i=1;i<n;i++){
            int num1=nums[i]%2;
            int num2=nums[i-1]%2;
            if(num1==num2){
                return false;
            }
        }
        return true;
    }
};