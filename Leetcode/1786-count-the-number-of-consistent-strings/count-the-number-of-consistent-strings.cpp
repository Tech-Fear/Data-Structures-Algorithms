class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>mp;
        int count=0;
        for(auto &i:allowed) mp[i]++;
        for(auto &word:words){
            int len=0;
            for(auto &ch:word){
                if(mp.find(ch)==mp.end()) break;
                len++;
            }
            if(len==word.size())
                count++;
        }
        return count;
    }
};