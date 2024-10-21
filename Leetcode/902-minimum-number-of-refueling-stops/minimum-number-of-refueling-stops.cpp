class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        stations.push_back({target,0});
        int minStops=0,prevStation=0;

        for(auto &station:stations){
            int dist=station[0]-prevStation;
            startFuel-=dist;
            while(startFuel<0 && !pq.empty()){
                minStops++;
                startFuel+=pq.top();
                pq.pop();
            }

            if(startFuel<0) return -1;

            pq.push(station[1]);
            prevStation=station[0];
        }
        return minStops;
    }
};