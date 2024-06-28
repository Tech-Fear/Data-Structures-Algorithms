class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int element;
        for(int i=0;i<nums.size();i++){
            if(count==0) {
                element=nums[i];
                count=1;
            }
            else if(element==nums[i]){
                count++;
            }else{
                count--;
            }
        }
        return element;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '@';
}();