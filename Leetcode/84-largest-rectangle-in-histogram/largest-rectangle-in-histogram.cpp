class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> smallLe(n, -1);
        vector<int> smallRi(n, n);
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                smallLe[i] = st.top();
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            st.pop();
        }
        
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                smallRi[i] = st.top();
            }
            st.push(i);
        }
        
        int area = 0;
        for(int i = 0; i < n; i++) {
            area = max(area, heights[i] * (smallRi[i] - smallLe[i] - 1));
        }
        return area;
    }
};
