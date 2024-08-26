class Solution {
private:
    const int size = 3 * (1e5);
    vector<int> primes;

    void sieve() {
        primes.assign(size + 1, 1);
        primes[0] = primes[1] = 0;
        for (long long i = 2; i * i <= size; i++) {
            if (primes[i]) {
                for (long long j = i * i; j <= size; j += i) {
                    primes[j] = 0;
                }
            }
        }
    }

public:
    Solution() {
        primes.resize(size + 1);
        sieve();
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            if (primes[nums[l]] && primes[nums[r]]) {
                ans = max(ans, r - l);
                l++;
                r--;
            } else if (!primes[nums[l]]) {
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};