#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<long long> st;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(1);
        st.insert(1);
        vector<int> fact = {2, 3, 5};
        
        for(int i = 0; i < n; i++) {
            long long num = pq.top();
            pq.pop();
            if(i == n - 1) return (int)num;
            for(int &f : fact) {
                long long new_num = f * num;
                if(st.find(new_num) == st.end()) {
                    st.insert(new_num);
                    pq.push(new_num);
                }
            }
        }
        return -1;
    }
};
