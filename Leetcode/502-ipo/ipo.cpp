class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; ++i) {
            projects[i] = {capital[i], profits[i]};
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxProfitHeap;
        int i = 0;

        while (k > 0) {
            while (i < n && projects[i].first <= w) {
                maxProfitHeap.push(projects[i].second);
                ++i;
            }

            if (maxProfitHeap.empty()) break;

            w += maxProfitHeap.top();
            maxProfitHeap.pop();
            
            --k;
        }

        return w;
    }
};
