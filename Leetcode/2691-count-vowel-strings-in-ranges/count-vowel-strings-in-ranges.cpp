class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char>vow={'a','e','i','o','u'};
        vector<int>isMatch(words.size(),0);
        int j=0;
        for(auto &i:words){
            int n=i.length();
            if(vow.find(i[0])!=vow.end() && vow.find(i[n-1])!=vow.end()){
                isMatch[j]=1;
            }
            j++;
        }
        vector<int>preSum(words.size());
        preSum[0]=isMatch[0];
        for(int i=1;i<words.size();i++){
            preSum[i]=preSum[i-1]+isMatch[i];
        }
        vector<int>ans;
        for(auto &que:queries){
            int l=que[0];
            int r=que[1];
            ans.push_back(l == 0 ? preSum[r] : preSum[r] - preSum[l - 1]);
        }
        return ans;
    }
};