class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        return x+y>=target && (target% gcd(x,y))==0;
    }
};