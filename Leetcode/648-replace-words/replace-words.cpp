class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) 
    {
        set<string>st(dictionary.begin(), dictionary.end());
        string word, ans;
        stringstream s(sentence);
        while(s >> word)
        {
            string str;
            bool flag = false;
            for(char ch:word)
            {
                str += ch;
                if(st.count(str))
                {
                    flag = true;
                    break;
                }
            }
            ans += (flag ? str : word);
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};