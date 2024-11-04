class Solution {
public:
    int minimumChairs(string s) {
        int temp=0;
        int mChairs=0;
        for(char &c:s){
            if(c=='E') temp++;
            else temp--;
            mChairs=max(mChairs,temp);
        }
        return mChairs;
    }
};