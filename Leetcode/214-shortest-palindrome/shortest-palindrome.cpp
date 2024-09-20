class Solution {
public:
    string shortestPalindrome(string s) {
        string z=s;
        int n=s.length();
        reverse(z.begin(),z.end());
        cout<<s<<" "<<z<<" ";
        for(int i=0;i<s.length();i++){
            if(!memcmp(s.c_str(),z.c_str()+i,n-i)){
                return z.substr(0,i)+s;
            }
        }
        return z+s;
    }
};