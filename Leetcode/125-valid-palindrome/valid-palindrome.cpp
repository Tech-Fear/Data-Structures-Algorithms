class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(auto &ch:s){
            if(ch>='a'&&ch<='z'){
                temp+=ch;
            }else if(ch>='A' && ch<='Z'){
                temp+=(char)(ch+32);
            }else if(ch>='0' && ch<='9'){
                temp+=ch;
            }
        }
        int size=temp.size();
        for(int i=0;i<size/2;i++){
            if(temp[i]!=temp[size-1-i]){
                return false;
            }
        }
        return true;
    }
};