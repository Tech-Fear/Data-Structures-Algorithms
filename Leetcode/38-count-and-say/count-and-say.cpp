class Solution {
public:
    string helper(string count){
        int index=0;
        string newStr;
        while(index<count.size()){
            int c=0;
            char cur_char=count[index];
            while(index<count.size() && cur_char==count[index]){
                c++;
                index++;
            }
            newStr+=to_string(c)+cur_char;
        }
        return newStr;
    }
    string countAndSay(int n) {
        string count="1";
        int i=1;
        while(i<n){
            count=helper(count);
            i++;
        }
        return count;
    }
};