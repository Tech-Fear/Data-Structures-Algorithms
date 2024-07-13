class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int, int>> vec;
        vector<int> ans;
        
        for (int i = 0; i < positions.size(); i++) {
            vec.push_back({positions[i], i});
        }
        sort(vec.begin(), vec.end());
        stack<pair<int, int>> st;
        
        for (int i = 0; i < healths.size(); ++i) {
            int idx = vec[i].second;
            bool survived = true;

            while (!st.empty() && directions[st.top().second] == 'R' && directions[idx] == 'L') {
                int prevIdx = st.top().second;
                if (healths[prevIdx] > healths[idx]) {
                    healths[prevIdx]--;
                    survived = false;
                    break;
                } else if (healths[prevIdx] < healths[idx]) {
                    healths[idx]--;
                    st.pop();
                } else {
                    st.pop();
                    survived = false;
                    break;
                }
            }

            if (survived) {
                st.push({healths[idx], idx});
            }
        }
        
        while (!st.empty()) {
            ans.push_back(st.top().second);
            st.pop();
        }
        
        sort(ans.begin(), ans.end());
        
        vector<int> result;
        for (int i : ans) {
            result.push_back(healths[i]);
        }
        
        return result;
    }
};
auto init=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'D';
}();