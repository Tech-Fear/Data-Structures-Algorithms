class Solution {
public:
    unordered_map<string,vector<int>>mp;
    vector<int> diffWaysToCompute(string expression) {
        if(mp.find(expression)!=mp.end()){
            return mp[expression];
        }
        vector<int>result;
        for(int i=0;i<expression.length();i++){
            char ch=expression[i];
            if(ch=='*' || ch=='-' || ch=='+'){
                vector<int>left=diffWaysToCompute(expression.substr(0,i));
                vector<int>right=diffWaysToCompute(expression.substr(i+1));
                for(int &j:left){
                    for(int &k:right){
                        if(ch=='+') result.push_back(j+k);
                        if(ch=='-') result.push_back(j-k);
                        if(ch=='*') result.push_back(j*k);
                    }
                }
            }
        }
        if(result.empty()){
            result.push_back(stoi(expression));
        }
        mp[expression]=result;
        return result;
    }
};