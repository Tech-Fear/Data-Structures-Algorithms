class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>starts,end_time;
        for(auto &interval:intervals){
            starts.push_back(interval[0]);
            end_time.push_back(interval[1]);
        }
        sort(starts.begin(),starts.end());
        sort(end_time.begin(),end_time.end());
        int endPtr=0,count=0;
        for(int start:starts){
            if(start>end_time[endPtr]){
                endPtr++;
            }else count++;
        }
        return count ;
    }
};