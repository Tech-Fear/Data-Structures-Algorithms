class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        vector<string> ans;
        auto processSentence = [&](const string &s) {
            stringstream ss(s);
            string word;
            while (ss >> word) {
                mp[word]++;
            }
        };
        processSentence(s1);
        processSentence(s2);
        for (auto &entry : mp) {
            if (entry.second == 1) {
                ans.push_back(entry.first);
            }
        }
        return ans;
    }
};
