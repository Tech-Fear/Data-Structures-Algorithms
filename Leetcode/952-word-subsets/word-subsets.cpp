class Solution {
private:
    bool isValid(vector<int>&source,vector<int>&dest){
        for(int i=0;i<26;i++){
            if(source[i]<dest[i]) return false;
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>res;
        vector<int>target(26,0);
        for(string &b:words2){
            vector<int>temp(26,0);
            for(char &c:b){
                temp[c-'a']++;
                target[c-'a']=max(target[c-'a'],temp[c-'a']);
            }
        }
        for(string &a:words1){
            vector<int>arr(26,0);
            for(char &c:a){
                arr[c-'a']++;
            }
            if(isValid(arr,target)){
                res.push_back(a);
            }
        }
        return res;
    }
};
auto init=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'X';
}();