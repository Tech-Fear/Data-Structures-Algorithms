class Solution {
public:
    void reverse(vector<int>&nums,int i,int j){
        while (i < j) {
            swap(nums[i], nums[j-1]);
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        reverse(nums,0,n);
        reverse(nums,0,k);
        reverse(nums,k,n);
    }
};