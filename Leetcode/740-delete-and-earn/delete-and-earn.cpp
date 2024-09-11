class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        vector<int>arr;
        for(auto &i:st){
            arr.push_back(i);
        }
        unordered_map<int,int>mp;
        int earn1=0,earn2=0;
        for(auto &i:nums){
            mp[i]++;
        }
        for(int i=0;i<arr.size();i++){
            int curEarn=arr[i]*mp[arr[i]];
            if(i>0 and arr[i]==arr[i-1]+1){
                int temp=earn2;
                earn2=max(earn2,curEarn+earn1);
                earn1=temp;
            }else {
                int temp=earn1;
                earn1=earn2;
                earn2=curEarn+earn2;
            }
        }
        return earn2;
    }
};