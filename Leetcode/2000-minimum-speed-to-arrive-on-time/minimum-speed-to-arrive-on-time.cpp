class Solution {
public:
    double speed(vector<int>& dist,int mid){
        double ans=0;
        for(int i=0;i<dist.size();i++){
            ans=ceil(ans);
            ans+=(dist[i]/(double)mid);
        }
        return ans;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int maX=*max_element(dist.begin(),dist.end());
        int l=1,r=1e9;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            double x=speed(dist,mid);
            if(x<=hour){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};