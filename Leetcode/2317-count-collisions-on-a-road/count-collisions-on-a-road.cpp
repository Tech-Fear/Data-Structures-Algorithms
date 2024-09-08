class Solution {
public:
  int countCollisions(string s) {
    // r = 1 , l = -1 , s = 0;
    stack<int> stk;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'R')
        stk.push(1);
      else if (s[i] == 'S') {
        while (!stk.empty() && stk.top() == 1) {
          stk.pop();
          ans++;
        }
        stk.push(0);
      } else {
        int flag = 0;
        while (!stk.empty() && stk.top() == 1) {
          if (flag == 0) {
            ans += 2;
            flag = 1;
          }
          else{
            ans++;
          }
          stk.pop();
        }
        if(flag == 0 && !stk.empty() && stk.top() == 0){
          ans++;
          flag = 1;
        }
        if(flag) stk.push(0);
      }
    }
    return ans;
  }
};