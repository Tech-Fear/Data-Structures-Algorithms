class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int len=groups.size();
        vector<string>ans;
        ans.push_back(words[0]);
        for(int i=1;i<len;i++){
            if(groups[i]!=groups[i-1]){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};