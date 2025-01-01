class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int leftZeros = 0, rightOnes = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                rightOnes++;
            }
        }
        
        int maxi = 0;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                leftZeros++;
            }

            if (s[i] == '1') {
                rightOnes--;
            }

            int tot = leftZeros + rightOnes;
            maxi = max(maxi, tot);
        }

        return maxi;
    }
};
