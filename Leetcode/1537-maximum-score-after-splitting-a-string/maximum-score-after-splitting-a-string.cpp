class Solution {
public:
    int total(string l,string r){
        int tot=0;
        for(int i=0;i<r.length();i++){
            tot+=(r[i]-'0');
        }
        for(int i=0;i<l.length();i++){
            if(l[i]=='0'){
                tot+=1;
            }
        }
        return tot;
    }
    int maxScore(string s) {
        int maxi=0;
        int n=s.length();
        for(int i=1;i<n;i++){
            int tot=0;
            string l=s.substr(0,i);
            string r=s.substr(i,n);
            tot=total(l,r);
            maxi=max(maxi,tot);
        }
        return maxi;
    }
};