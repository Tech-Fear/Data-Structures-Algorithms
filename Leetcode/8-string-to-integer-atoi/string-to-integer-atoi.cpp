class Solution {
public:
    int myAtoi(string s) {
        bool isNegative = false;
        int i = 0;
        int n = s.length();
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                isNegative = true;
            }
            i++;
        }
        
        long long digit = 0;
        while (i < n) {
            int x = s[i] - '0';
            if (x >= 0 && x <= 9) {
                digit = digit * 10 + x;
                if (digit > INT_MAX) {
                    break;
                }
            } else {
                break;
            }
            i++;
        }
        
        if (isNegative) {
            digit = -digit;
        }
        if (digit > INT_MAX) {
            return INT_MAX;
        } else if (digit < INT_MIN) {
            return INT_MIN;
        }
        return static_cast<int>(digit);
    }
};