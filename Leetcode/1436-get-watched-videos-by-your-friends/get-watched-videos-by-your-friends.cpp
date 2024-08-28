class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_map<int,vector<int>>adjList;
        for(int i=0;i<friends.size();i++){
            for(auto &d:friends[i]){
                adjList[i].push_back(d);
                adjList[d].push_back(i);
            }
        }
        queue<int>que;
        que.push(id);
        vector<bool>visited(friends.size(),false);
        visited[id]=true;
        // friends at level k
        while(level>0){
            level-=1;
            int size=que.size();
            for(int i=0;i<size;i++){
                int j=que.front();que.pop();
                for(int &k:adjList[j]){
                    if(!visited[k]){
                        visited[k]=true;
                        que.push(k);
                    }

                }
            }
        }
        // movies they watched by freq
        unordered_map<string,int>frq;
        vector<string>ans;
        while(!que.empty()){
            int t=que.front();
            que.pop();
            for(auto &v:watchedVideos[t]){
                if(frq.find(v)==frq.end()){
                    ans.push_back(v);
                }
                frq[v]++;
            }
        }
        sort(ans.begin(),ans.end(),[&](string &a,string &b){
            if(frq[a]==frq[b]) return a<b;
            return frq[a]<frq[b];
        });
        return ans;
    }
};