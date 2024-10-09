class Solution {
public:
    int minAddToMakeValid(string s) {
        // Using stack TC: O(len(s)) and SC: O(N)
        // stack<char>stk;
        // int closingNotMatched=0;
        // for(char &ch:s){
        //     if(ch=='('){
        //         stk.push(ch);
        //     }else{
        //         if(stk.empty()){
        //             closingNotMatched++;
        //         }
        //         else stk.pop();
        //     }
        // }
        // return stk.size()+closingNotMatched;

        // Approch 2 TC: O(len(s)) and space Complexity: O(1)

        int open=0,closingUnmatch=0;
        for(auto &ch:s){
            if(ch=='('){
                open++;
            }else{
                if(open==0){
                    closingUnmatch++;
                }else{
                    open--;
                }
            }
        }
        return open+closingUnmatch;
    }
};