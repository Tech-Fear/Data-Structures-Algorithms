class Solution {
public:
    bool isPalindrome(int x) {
        long long z=0;
        int copy=x;
        while(copy>0){
            z=z*10+copy%10;
            copy/=10;
        }
        if(x==z){
            return true;
        }
        return false;
    }
};