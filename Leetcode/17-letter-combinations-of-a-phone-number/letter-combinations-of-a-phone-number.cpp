class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        vector<string>result;
        string cur;
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        generate(digits,0,result,cur,mp);
        return result;
    }
private:
    void generate(string digits,int ind,vector<string>&res,string &cur,unordered_map<char,string>&mp){
        if(digits.length()==ind){
            res.push_back(cur);
        }
        char digit=digits[ind];
        string str=mp[digit];
        for(char letter:str){
            cur.push_back(letter);
            generate(digits,ind+1,res,cur,mp);
            cur.pop_back();
        }
    }
};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return '#';
}();