class Solution {
public:
    int digitSum(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(auto &num:nums){
            int x=digitSum(num);
            if(x<mini){
                mini=x;
            }
        }
        return mini;
    }
};