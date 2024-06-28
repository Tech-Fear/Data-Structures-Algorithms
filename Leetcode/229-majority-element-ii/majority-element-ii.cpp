class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int maj1=INT_MIN;
        int maj2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(maj1==nums[i]){
                count1++;
            }else if(maj2==nums[i]){
                count2++;
            }else if(count1==0){
                count1+=1;
                maj1=nums[i];
            }else if(count2==0){
                maj2=nums[i];
                count2++;
            }else{
                count2--;
                count1--;
            }
        }
        vector<int>ans;
        int freq1=0,freq2=0;
        for(int &num:nums){
            if(num==maj1){
                freq1++;
            }else if(num==maj2){
                freq2++;
            }
        }
        if(freq1>(nums.size()/3)) ans.push_back(maj1);
        if(freq2>(nums.size()/3)) ans.push_back(maj2);
        return ans;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'W';
}();