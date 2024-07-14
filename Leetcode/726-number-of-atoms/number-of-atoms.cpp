class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> count;
        stack<map<string, int>> stk;
        int n = formula.length();
        for (int i = 0; i < n; ) {
            if (formula[i] == '(') {
                stk.push(count);
                count.clear();
                i++;
            } else if (formula[i] == ')') {
                int iStart = ++i, multiplicity = 1;
                while (i < n && isdigit(formula[i])) i++;
                if (i > iStart) multiplicity = stoi(formula.substr(iStart, i - iStart));
                if (!stk.empty()) {
                    auto top = stk.top(); stk.pop();
                    for (auto &p : count) top[p.first] += p.second * multiplicity;
                    count = top;
                }
            } else {
                int iStart = i++;
                while (i < n && islower(formula[i])) i++;
                string name = formula.substr(iStart, i - iStart);
                iStart = i;
                while (i < n && isdigit(formula[i])) i++;
                int multiplicity = (i > iStart) ? stoi(formula.substr(iStart, i - iStart)) : 1;
                count[name] += multiplicity;
            }
        }
        
        string result;
        for (auto &p : count) {
            result += p.first;
            if (p.second > 1) result += to_string(p.second);
        }
        return result;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '#';
}();