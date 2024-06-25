class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        stack<int> st;
        vector<int> res(temperatures.size());
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if (st.empty()) {
                res[i] = 0;
            } else {
                res[i] = st.top() - i;
            }
            st.push(i);
        }
        return res;
    }
};
