const int mod = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> left(arr.size());
        vector<int> right(arr.size());
        int n = arr.size();
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            left[i] = stk.empty() ? i + 1 : i - stk.top();
            stk.push(i);
        }
        while (!stk.empty()) {
            stk.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            right[i] = stk.empty() ? n - i : stk.top() - i;
            stk.push(i);
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + (1LL * arr[i] * left[i] * right[i]) % mod) % mod;
        }

        return res;
    }
};