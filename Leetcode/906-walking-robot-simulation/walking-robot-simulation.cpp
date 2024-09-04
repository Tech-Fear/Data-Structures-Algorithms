class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>st;
        for(auto &ob:obstacles){
            st.insert(to_string((ob[0]))+"_"+to_string(ob[1]));
        }
        int x=0,y=0,maxD=0;
        //Pointing to North 
        pair<int,int>dir={0,1};
        for(auto &com:commands){
            if(com==-2){
                dir={-dir.second,dir.first};
            }else if(com==-1){
                dir={dir.second,-dir.first};
            }else{
                for(int step=0;step<com;step++){
                    int newX= x+dir.first;
                    int newY=y+dir.second;
                    string nextKey=to_string(newX)+"_"+to_string(newY);
                    if(st.find(nextKey)!=st.end())
                        break;
                    x=newX;
                    y=newY;
                    maxD=max(maxD,x*x+y*y);
                }
            }
        }
        return maxD;
    }
};