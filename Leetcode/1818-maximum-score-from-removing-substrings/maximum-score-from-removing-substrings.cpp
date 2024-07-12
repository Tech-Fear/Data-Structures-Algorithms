#define fast_cin() ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
class Solution {
private:
    pair<string,int> remove(string &s,string &match){
        fast_cin();
        stack<char>st;
        int pairs=0;
        for(char &ch:s){
            if(ch==match[1] && !st.empty() && st.top()==match[0]){
                st.pop();
                pairs++;
            }else{
                st.push(ch);
            }
        }
        string str="";
        while(!st.empty()){
            str.push_back(st.top());
            st.pop();
        }
       reverse(begin(str),end(str));
       return {str,pairs};
    }
public:
    int maximumGain(string s, int x, int y) {
        fast_cin();
        int n=s.length();
        int score=0;
        string match=(x>=y?"ab":"ba");
        string match2=(match=="ab"?"ba":"ab");
        pair<string,int> p=remove(s,match);
        score+=((p.second)*max(x,y));
        p=remove(p.first,match2);
        score+=((p.second)*min(x,y));
        return score;
    }
};
//approch 1
/* got memory limit exceeded in  
    #define fast_cin() ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        fast_cin();
        stack<char>st;
        string s2="";
        int result=0;
        int maxi=max(x,y),mini=min(x,y);
        string match=(x>=y?"ab":"ba");
        string match2=(match=="ab"?"ba":"ab");
            for(char c:s){
                if(c==match[1] && !st.empty()&& st.top()==match[0]){
                    st.pop();
                    result+=maxi;
                }else{
                    st.push(c);
                }
            }
            // while (!st.empty()) {    //this while loop is causing the memory limit exceed due to recreation during concatenation
            //     s2 = st.top() + s2; 
            //     st.pop();
            // }
            for(char c:s2){
                if(c==match2[1] && !st.empty()&& st.top()==match2[0]){
                    st.pop();
                    result+=mini;
                }else{
                    st.push(c);
                }
            }
            return result;    
    }
};

*/