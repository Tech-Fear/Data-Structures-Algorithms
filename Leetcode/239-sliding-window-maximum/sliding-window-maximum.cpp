class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int>ans;
        int n=nums.size();
        multiset<int>store;
        for(int i=0;i<k;i++){
            store.insert(nums[i]);
        }
        auto it=store.rbegin();
        ans.push_back(*it);
        int i=0,j=k;
        while(j<n){
            store.erase(store.find(nums[i]));
            store.insert(nums[j]);
            auto it2=store.rbegin();
            cout<<*it2<<" ";
            ans.push_back(*it2);
            i++;j++;
        }
        return ans;
    }
};