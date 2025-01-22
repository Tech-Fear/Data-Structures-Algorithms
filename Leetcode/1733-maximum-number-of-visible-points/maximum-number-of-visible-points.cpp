class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;
        int x = location[0];
        int y = location[1];
        int answer = 0;
        double pi=acos(-1.0);
        for (const auto& p : points) {
            if (p[0] == x && p[1] == y) {
                answer++;
            } else {
                int dx = p[0] - x;
                int dy = p[1] - y;
                double angle1 = atan2(dy,dx); 
                double angle2 = angle1 * (180) / pi;
                angles.push_back(angle2);
            }
        }

        sort(angles.begin(),angles.end());
        int n = angles.size();
        for(int i= 0; i < n ; ++i) {
            angles.push_back(angles[i] + 360);
        }
        int start = 0;
        int cnt = 0;
        for(int i =0; i < angles.size(); ++i) {
            if(angles[i] - angles[start] > angle){
                start++;
            }
            cnt = max(cnt, i - start + 1);
        }
        answer += cnt;
        return answer;
    }
};