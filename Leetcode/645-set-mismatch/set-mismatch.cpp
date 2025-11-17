class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n= nums.size();
        long long sumAct = (n*(n+1))/2;
        long long sumSq = ((sumAct) * (2*n + 1))/3;
        long long arrSum = accumulate(nums.begin(), nums.end(),0);
        long long arrSqSum = 0;
        for(int num:nums){
            arrSqSum += num*num;
        }
        long long sumDiff = arrSum-sumAct;
        long long sqSumDiff = arrSqSum - sumSq;
        long long sumPlusDiff = sqSumDiff/sumDiff;
        int y = (sumPlusDiff + sumDiff)/2;
        int x = y-sumDiff;
        return {y,x};



    }
};