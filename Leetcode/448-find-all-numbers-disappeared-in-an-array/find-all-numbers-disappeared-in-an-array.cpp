class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int> map;
        for(int num:nums){
            map[num]++;
        }
        for(int i =1; i<=nums.size();i++){
            if(map.find(i) == map.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};