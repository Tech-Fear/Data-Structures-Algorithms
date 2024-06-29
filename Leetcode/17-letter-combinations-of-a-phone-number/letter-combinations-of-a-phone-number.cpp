class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> result;
        string current;
        backtrack(digits, 0, mp, current, result);
        return result;
    }
private:
    void backtrack(const string &digits, int index, const unordered_map<char, string> &mp, string &current, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        char digit = digits[index];
        const string &letters = mp.at(digit);
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index + 1, mp, current, result);
            current.pop_back();
        }
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '#';
}();