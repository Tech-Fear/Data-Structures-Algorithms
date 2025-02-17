class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<pair<int,int>>palind;
        auto expand=[&](int left,int right){
            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1>=k){
                    palind.push_back({left,right});
                }
                left--;
                right++;
            }
        };
        for(int i=0;i<n;i++){
            expand(i,i);
            expand(i,i+1);
        }
        sort(palind.begin(),palind.end(),[&](pair<int,int>&p1,pair<int,int>&p2){
            return p1.second<p2.second;
        });
        int count=0;
        int lastEnd=-1;
        for(auto &p:palind){
            int start=p.first;
            int end=p.second;
            if(start>lastEnd){
                lastEnd=end;
                count++;
            }
        }
        return count;
    }
};