class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>win;
        map<int,int>totalPlayed;
        
        for(auto &match:matches){
            win[match[0]]++;
            totalPlayed[match[0]]++;
            totalPlayed[match[1]]++;
        }
        vector<int>allWon;
        vector<int>lost1;
        for(auto &it:totalPlayed){
         int player=it.first;
         int gamesPlayed=it.second;
         int wins=win[player];
         if(wins==gamesPlayed){
            allWon.push_back(player);
         }
         if(wins==gamesPlayed-1) lost1.push_back(player);
        }
        vector<vector<int>>ans;
        ans.push_back(allWon);
        ans.push_back(lost1);
        
        return ans;
    }
};