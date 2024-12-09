class NumArray {
public:
    vector<int>arr;
    NumArray(vector<int>& nums) {
        arr.resize(nums.size());
        arr[0]=nums[0];
        for(int i=1;i<arr.size();i++){
            arr[i]=arr[i-1]+nums[i];
        }
    }
    int sumRange(int left, int right) {
        if(left==0){
            return arr[right];
        }
        else{
           return arr[right]-arr[left-1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */