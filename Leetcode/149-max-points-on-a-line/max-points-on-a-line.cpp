class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2) return n;
        int answer=0;
        for(int i=0;i<n;i++){
            unordered_map<string,int>slopes;
            int curMax=0;
            for(int j=i+1;j<n;j++){
                int dx=points[j][0] - points[i][0];
                int dy=points[j][1] - points[i][1];
                int hcf=__gcd(dy,dx);
                dx/=hcf;
                dy/=hcf;
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }else if (dx == 0) {
                    dy = abs(dy);
                }
                string slope=to_string(dy) + "/" + to_string(dx);
                slopes[slope]++;
                curMax=max(curMax,slopes[slope]);
            }
            answer=max(answer,curMax+1); // added one as the current point will not be counted 
        }
        return answer;
    }
};