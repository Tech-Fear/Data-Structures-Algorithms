class Solution {
public:
    unordered_set<int> seen;
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int digit = n % 10;
            totalSum += digit * digit;
            n /= 10;
        }
        return totalSum;
    }
    bool isHappy(int n) {
        if (n == 1)
            return true;
        if (seen.find(n) != seen.end())
            return false;
        seen.insert(n);
        return isHappy(getNext(n));
    }
};
