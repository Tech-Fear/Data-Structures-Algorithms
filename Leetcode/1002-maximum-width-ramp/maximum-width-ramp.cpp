class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>>temp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
        }
        sort(temp.begin(),temp.end());
        int maxWidth=0;
        int minEle=temp[0].second;
        for(int i=1;i<n;i++){
            int curInd=temp[i].second;
            if(curInd>minEle){
                maxWidth=max(maxWidth,curInd-minEle);
            }else{
                minEle=curInd;
            }
        }
        return maxWidth;
    }
};