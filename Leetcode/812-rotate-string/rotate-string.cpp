class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        string fin=s+s;
        int n=fin.size();
        int m=goal.size();
        for(int i=0;i<n-m;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(fin[i+j]==goal[j]) count++;
                if(count==m) return true;
            }
        }
        return false;
    }
};