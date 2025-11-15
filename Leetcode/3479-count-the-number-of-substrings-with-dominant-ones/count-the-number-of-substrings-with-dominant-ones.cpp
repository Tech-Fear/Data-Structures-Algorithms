class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> pre(n + 1);
        pre[0] = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0 || (i > 0 && s[i - 1] == '0')) {
                pre[i + 1] = i;
            } else {
                pre[i + 1] = pre[i];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int zeroCount = s[i - 1] == '0';
            int j = i;
            while (j > 0 && zeroCount * zeroCount <= n) {
                int cnt1 = (i - pre[j]) - zeroCount;
                if (zeroCount * zeroCount <= cnt1) {
                    res += min(j - pre[j], cnt1 - zeroCount * zeroCount + 1);
                }
                j = pre[j];
                zeroCount++;
            }
        }
        return res;
    }
};