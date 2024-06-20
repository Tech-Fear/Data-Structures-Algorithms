class Solution {
public:
    bool isValid(vector<int>& position,int &mid,int &m,int &n){
        int prev=position[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(position[i]-prev>=mid){
                count++;
                prev=position[i];
            }
            if(count==m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=position.size();
        sort(position.begin(),position.end());
        int min=1;
        int result;
        int max=(position[n-1]-position[0])/(m-1);
        while(min<=max){
            int mid=min+(max-min)/2;
            if(isValid(position,mid,m,n)){
                result = mid;
                min=mid+1;
            }else{
                max=mid-1;
            }
        }
        return result;
    }
};