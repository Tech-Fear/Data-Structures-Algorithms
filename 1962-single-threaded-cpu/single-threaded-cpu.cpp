class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>result;
        int n=tasks.size();
        vector<array<int,3>>sortedTask;
        for(int i=0;i<n;i++){
            sortedTask.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(begin(sortedTask),end(sortedTask));
        long long cur_time=0;
        int index=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        while(index<n || !pq.empty()){
            if(pq.empty() && cur_time<sortedTask[index][0]){
                cur_time=sortedTask[index][0];
            }
            while(index<n && sortedTask[index][0]<=cur_time){
                pq.push({sortedTask[index][1],sortedTask[index][2]});
                index++;
            }
            pair<int,int>temp=pq.top();
            pq.pop();

            cur_time+=temp.first;
            result.push_back(temp.second);
        }
        return result;
    }
};