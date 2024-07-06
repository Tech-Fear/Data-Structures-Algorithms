class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle=(n-1)*2;
        int position=time%cycle;
        if(position<n){
            return position+1;
        }
        return 2*n-position-1;
    }
};