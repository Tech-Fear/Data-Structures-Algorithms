class Solution {
public:
    int arrangeCoins(int n) {
       int t=1;
       int c=0;
       while(true){
        if(n<t){
            return c;
        }
        n-=t;
        t++;
        c++;
       } 
       return n;
    }
};