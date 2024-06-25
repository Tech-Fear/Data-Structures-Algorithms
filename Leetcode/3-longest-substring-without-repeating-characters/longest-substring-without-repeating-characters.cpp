class Solution {
public:
    int lengthOfLongestSubstring(string s) {
          unordered_map<char,int>mp;
  int ans=0;
  int l=0;
  for(int i=0;i<s.length();i++){
    if(mp.count(s[i])==0||mp[s[i]]<l){
      ans=max(ans,i-l+1);
      mp[s[i]]=i;
    }else{
      l=mp[s[i]]+1;
      mp[s[i]]=i;
    }
  }
    return ans;
    }
};