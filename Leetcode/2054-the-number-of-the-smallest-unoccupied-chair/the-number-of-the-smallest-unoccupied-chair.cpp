class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int unsat=0;
        priority_queue<int,vector<int>,greater<>>emptyChairs;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> occupied;
        for(int i=0;i<times.size();i++){
            times[i].push_back(i);
        }
        sort(times.begin(),times.end());
        for(auto &time:times){
            int arrival=time[0];
            int leaving=time[1];
            int frnd=time[2];
            while(!occupied.empty() && occupied.top().first<=arrival){
                emptyChairs.push(occupied.top().second);
                occupied.pop();
            }
            if(frnd==targetFriend){
                return emptyChairs.empty()?unsat:emptyChairs.top();
            }
            if(emptyChairs.empty()){
                occupied.emplace(leaving,unsat++);
            }else{
                occupied.emplace(leaving,emptyChairs.top());
                emptyChairs.pop();
            }
        }
        return -1;
    }
};