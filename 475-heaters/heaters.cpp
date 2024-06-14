class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int i=0,j=0;
        int n=houses.size();
        int m=heaters.size();
        long long ans=0;
        vector<vector<int>>closest;
        while(i<n){
            while(j<m and heaters[j]<=houses[i]){
                j++;
            }
            vector<int>dist;
            if(j!=m){
                dist.push_back(heaters[j]);
            }
            if(j-1>=0) dist.push_back(heaters[j-1]);
            closest.push_back(dist);
            i++;
        }
        long long low=0,high=1e12;
        while(low<=high){
            long long mid=low+(high-low)/2;
            bool flag=true;
            for(int i=0;i<n;i++){
                if(closest[i].size()==1){
                    if(abs(closest[i][0]-houses[i])>mid) flag=false;
                }else{
                    if(min(abs(closest[i][0]-houses[i]),abs(closest[i][1]-houses[i]))>mid) flag=false; 
                }
            }
            if(flag){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return (int)ans;
    }
};