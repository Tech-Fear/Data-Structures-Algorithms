class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(auto &num:nums){
            pq.push(num);
        }
        int ans=0;
        while(pq.top()<k){
            long long x=pq.top();
            pq.pop();
            long long y=pq.top();
            pq.pop();
            pq.push(min(x,y)*2*1LL + max(x,y));
            ans++;
        }
        return ans;
    }
};