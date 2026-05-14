class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> pref(n + 1, 0);
        vector<int> suf(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + (customers[i - 1] == 'N');
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + (customers[i] == 'Y');
        }
        int ans = 0;
        int minPenalty = INT_MAX;
        for (int i = 0; i <= n; i++) {
            int curPenalty = pref[i] + suf[i];
            if (curPenalty < minPenalty) {
                minPenalty = curPenalty;
                ans = i;
            }
        }
        return ans;
    }
};