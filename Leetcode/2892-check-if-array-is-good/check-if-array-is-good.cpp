class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxElem = *max_element(nums.begin(),nums.end());
        int countMax = count(nums.begin(), nums.end(), maxElem);
        bool isGood = countMax == 2 && nums.size()==maxElem+1;
        vector<int> counts(maxElem+1,0);
        for(int i=0;i<nums.size();i++){
            counts[nums[i]]++;
        }
        int c = 0;
        for(int i=1;i<=maxElem;i++){
            if(counts[i]>1 || counts[i] ==0){
                c++;
            }
        }
        return isGood && c==1;
    }
};