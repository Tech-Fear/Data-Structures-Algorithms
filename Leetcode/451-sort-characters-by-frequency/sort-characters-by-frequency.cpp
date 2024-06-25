class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto &i:s){
            mp[i]++;
        }
        vector<pair<char,int>>pr;
        for(auto &va:mp){
            pr.push_back(va);
        }
        sort(pr.begin(),pr.end(),[](const pair<char,int>&p1, const pair<char,int>&p2){
            return p1.second>p2.second;
        });
        string ans="";
        for(auto &p:pr){
            ans+=string(p.second,p.first);
        }
        return ans;
    }
};