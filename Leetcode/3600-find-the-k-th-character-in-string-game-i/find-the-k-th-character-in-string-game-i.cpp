class Solution {
public:
    char kthCharacter(int k) {
        int count=0;
        while((1<<count)<k){
            count++;
        }
        string s="a";
        for(int j=0;j<count;j++){
            int n=s.length();
            for(int i=0;i<n;i++){
                s+=(s[i]+1);
            }
        }
        return s[k-1];
    }
};