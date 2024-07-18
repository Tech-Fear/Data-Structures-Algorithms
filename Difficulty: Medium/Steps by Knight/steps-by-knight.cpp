//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{   private:
    bool isValid(int i,int j,int N,vector<vector<bool>>&visited){
        if(i<N && j<N && i>=0 && j>=0 && visited[i][j]==false) return true;
        return false;
    }
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int srcX=KnightPos[0]-1,srcY=KnightPos[1]-1,destX=TargetPos[0]-1,destY=TargetPos[1]-1;
	    int count=0;
	    if(srcX==destX && srcY==destY){
	        return count;
	    }
	    int dx[8]={2,2,-2,-2,1,-1,1,-1};
	    int dy[8]={1,-1,1,-1,2,2,-2,-2};
	    queue<pair<int,int>>que;
	    vector<vector<bool>>visited(N,vector<bool>(N,false));
	    visited[srcX][srcY]=true;
	    que.push({srcX,srcY});
	    while(!que.empty()){
	        int n=que.size();
	        count++;
	        while(n--){
	            pair<int,int> val=que.front();
	            que.pop();
	            for(int i=0;i<=7;i++){
	                int x=dx[i]+val.first;
	                int y=dy[i]+val.second;
	                if(x==destX && y==destY) return count;
	                if(isValid(x,y,N,visited)){
	                    visited[x][y]=true;
	                    que.push({x,y});
	                }
	            }
	            
	        }
	    }
	    return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends