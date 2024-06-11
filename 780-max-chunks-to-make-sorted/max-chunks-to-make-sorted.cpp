class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        set<int> s1;
        int ans = 0;
        int max = 0;
        int n=arr.size();
        for (int i = 0; i < n; i++) {
            s1.insert(arr[i]);
            max = *max_element(s1.begin(), s1.end());
            if (i == max) {
                ans++;
            }
        }
        return ans;
    }
};