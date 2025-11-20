class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if (a[1] == b[1]) return a[0] > b[0];
        else return a[1] < b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();

        int a = -1, b = -1;

        for (int i = 0; i < n; i++){
            int start = intervals[i][0], end = intervals[i][1];

            bool a_in = (a >= start);
            bool b_in = (b >= start);

            if(a_in && b_in) continue;

            if(!a_in && !b_in){
                ans += 2;
                b = end;
                a = end - 1;
            }
            else {
                ans += 1;
                a = b;
                b = end;
            }
        }

        return ans;
    }
};