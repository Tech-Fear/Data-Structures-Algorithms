class Solution {
public:
    int mod = 1e9 + 7;

    int numSub(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        long long count = 0;
        long long count1 = 0;

        for (char c : s) {
            if (c == '1') {
                count1++;
            } else {
                count = (count + (count1 * (count1 + 1) / 2) % mod) % mod;
                count1 = 0;
            }
        }

        if (count1 > 0) {
            count = (count + (count1 * (count1 + 1) / 2) % mod) % mod;
        }

        return count;
    }
};
