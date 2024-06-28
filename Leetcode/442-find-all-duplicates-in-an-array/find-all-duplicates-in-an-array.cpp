class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;

        for(int num : nums) {
            int &to_node = nums[abs(num)-1];

            if(to_node < 0) {
                duplicates.push_back(abs(num));
                continue;
            }

            to_node *= -1; 
        }

        return duplicates;
    }
};