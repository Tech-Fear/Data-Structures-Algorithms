class Solution {
private:
    long long solve(long long i,long long count){
        if(i==1){
            return count;
        }
        if(i%2==0){
            return solve(i/2,count+1);
        }
        return solve(3*i + 1,count+1);
    }
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,long long>>steps;
        for(long long i=lo;i<=hi;i++){
            steps.push_back({i,solve(i,0)});
        }
        sort(steps.begin(),steps.end(),[&](pair<int ,long long>&a,pair<int ,long long>&b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second<b.second;
        });
        return steps[k-1].first;
    }
};