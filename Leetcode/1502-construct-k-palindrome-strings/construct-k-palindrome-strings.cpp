class Solution {
public:
    bool canConstruct(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(s.length()<k) return false;
        vector<int> freq(26, 0);
        for (auto& c : s) {
            freq[c - 'a']++;
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i]&1)
                count++;
        }
        return count <= k ? true : false;
    }
};