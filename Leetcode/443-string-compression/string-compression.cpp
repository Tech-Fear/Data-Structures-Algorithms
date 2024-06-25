class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int index=0,i=0;
        while(i<n){
            int count=0;
            char curr_char=chars[i];
            while(i<n && curr_char==chars[i]){
                count++;
                i++;
            }
            chars[index]=curr_char;
            index++;
            if(count>1){
                string count_char=to_string(count);
                for(char &st:count_char){
                    chars[index++]=st;
                }
            }
        }
        return index++;
    }
};