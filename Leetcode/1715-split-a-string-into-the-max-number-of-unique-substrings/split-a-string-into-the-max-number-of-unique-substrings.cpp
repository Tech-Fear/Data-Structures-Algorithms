class Solution {
public:
    void backtrack(string& s, int start, unordered_set<string>& seen,
                   int& maxCount) {
        if (start == s.length()) {
            maxCount = max(maxCount, (int)seen.size());
            return;
        }
        for (int end = start; end < s.length(); ++end) {
            string sub = s.substr(start, end - start + 1);
            if (seen.insert(sub).second) {
                backtrack(s, end + 1, seen, maxCount);
                seen.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        int maxCount = 0;
        backtrack(s, 0, seen, maxCount);
        return maxCount;
    }
};