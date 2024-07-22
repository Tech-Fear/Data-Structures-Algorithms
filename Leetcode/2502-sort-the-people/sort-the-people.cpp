class Solution {
private:
    static bool comp(pair<string,int>&p1,pair<string,int>&p2){
        return p1.second>p2.second;
    }
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>>vec;
        for(int i=0;i<heights.size();i++){
            vec.push_back({names[i],heights[i]});
        }
        sort(vec.begin(),vec.end(),comp);
        vector<string>ans;
        for(int i=0;i<vec.size();i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};