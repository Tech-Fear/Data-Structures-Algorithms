class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int,vector<int>>pq;
        for(auto &num:nums){
            pq.push(num);
        }
        long long score=0;
        while(!pq.empty() && k>0){
            int num=pq.top();
            pq.pop();
            score+=num;
            num=((num+2)/3);
            pq.push(num);
            k--;
        }
        return score;
    }
};