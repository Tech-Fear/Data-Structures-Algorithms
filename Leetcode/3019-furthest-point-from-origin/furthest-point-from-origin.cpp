class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cR = 0, cL = 0, cD = 0;
        for (char& c : moves) {
            if (c == 'R') {
                cR += 1;
            } else if (c == 'L') {
                cL += 1;
            } else {
                cD += 1;
            }
        }
        return abs(cR - cL) + cD;
    }
};