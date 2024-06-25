class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int>items;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
                items.insert(nums[i]);
        }
        int count=0;
        auto it=items.begin();
        while(it!=items.end()){
            count++;
            it++;
        }
        return count;
    }
};