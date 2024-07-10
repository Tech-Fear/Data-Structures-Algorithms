class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0;
        for(auto &i:logs){
            if(i=="../") {
                if(count>0)
                    count--;
                else continue;
            }
            else if(i=="./") continue;
            else count++;
        }
        return count;
    }

};
auto init=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();