class Solution {
private:
    static bool comp(pair<int,int>&p1,pair<int,int>&p2){
        return p1.second>p2.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        vector<pair<int,int>>vec;
        for(auto m:mp){
            vec.push_back({m.first,m.second});
        }
        sort(vec.begin(),vec.end(),comp);
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};