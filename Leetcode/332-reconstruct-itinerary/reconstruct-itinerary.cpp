class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>adjList;
        for(auto &t:tickets){
            adjList[t[0]].insert(t[1]);
        }
        vector<string>result;
        stack<string>stk;
        stk.push("JFK");
        while(!stk.empty()){
            string u=stk.top();
            if(adjList[u].empty()){
                result.push_back(u);
                stk.pop();
            }else{
                auto v=*adjList[u].begin();
                stk.push(v);
                adjList[u].erase(adjList[u].begin());
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};