class Solution {
private:
    void dijkastra(vector<vector<pair<int,int>>>&adjList,vector<vector<int>>&edges,vector<vector<int>>&dist,int source,int diff,int run){
        int n=adjList.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,source});
        dist[source][run]=0;
        while(!pq.empty()){
            auto [curDist,curNode]=pq.top();
            pq.pop();
            if(curDist>dist[curNode][run]) continue;
            for(auto &neigh:adjList[curNode]){
                int nextNode=neigh.first,edgeInd=neigh.second;
                int weight=edges[edgeInd][2];
                if(weight==-1) weight=1;
                if(run==1 && edges[edgeInd][2]==-1){
                    int newWeight=diff+dist[nextNode][0]-dist[curNode][1];
                    if(newWeight>weight){
                        edges[edgeInd][2]=weight=newWeight;
                    }
                }
                if(dist[nextNode][run]>dist[curNode][run]+weight){
                    dist[nextNode][run] = dist[curNode][run] + weight;
                    pq.push({dist[nextNode][run], nextNode});
                }
            }
        }
    }
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int,int>>>adjList(n);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adjList[b].emplace_back(a,i);
            adjList[a].emplace_back(b,i);
        }
        vector<vector<int>>dist(n,vector<int>(2,INT_MAX));
        dist[source][0]=dist[source][1]=0;
        dijkastra(adjList,edges,dist,source,0,0);
        int diff=target-dist[destination][0];
        if(diff<0) return {};
        dijkastra(adjList,edges,dist,source,diff,1);
        if(dist[destination][1]<target)return {};
        for(auto &edge:edges){
            if(edge[2]==-1)edge[2]=1;
        }
        return edges;
    }
};