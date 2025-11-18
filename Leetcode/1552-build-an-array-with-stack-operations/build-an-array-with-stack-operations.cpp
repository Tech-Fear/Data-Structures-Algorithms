class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> stk;
        vector<string> ans;
        int j=1;
        for(int i=0;i<target.size();i++){
            while(target[i]>j){
                ans.push_back("Push");
                ans.push_back("Pop");
                j++;
            }
            ans.push_back("Push");
            j++;
        }
        return ans;
    }
};