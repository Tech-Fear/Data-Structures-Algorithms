class Solution {
public:
    void reverseString(vector<char>& s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;j--;
        }
    }
};