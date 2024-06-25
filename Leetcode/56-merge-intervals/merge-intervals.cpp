class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int l=intervals[0][0],h=intervals[0][1];
        for(int i=0;i<intervals.size()-1;i++){
            if(h>=intervals[i+1][0]){
                h=max(h,intervals[i+1][1]);
            }else{
                ans.push_back({l,h});
                l=intervals[i+1][0];
                h=intervals[i+1][1];
            }
        }
        ans.push_back({l,h});
        return ans;
    }
};