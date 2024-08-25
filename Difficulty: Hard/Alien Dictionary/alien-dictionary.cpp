//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        // code here
        string ans="";
        if(n==0 || k==0) return ans;
        vector<int>indegree(k,0);
        unordered_map<char,vector<char>>mp;
        for(int i=1;i<n;i++){
            string prv=dict[i-1];
            string cur=dict[i];
            if((prv.length()==cur.length()+1)&&(prv.substr(0,cur.length())==cur)) return ans;
            for(int k=0;k<min(prv.size(),cur.size());k++){
                char c1=prv[k];
                char c2=cur[k];
                if(c1!=c2){
                    mp[c1].push_back(c2);
                    indegree[c2-'a']++;
                    break;
                }
            }
        }
        set<char>st;
        for(int i=0;i<n;i++){
            string s=dict[i];
            for(auto &c:s){
                st.insert(c);
            }
        }
        auto comp=[](const char &a,const char &b){
            return a>b;
        };
        priority_queue<char,vector<char>,decltype(comp)>pq(comp);
        for(const char &c:st){
            if(indegree[c-'a']==0){
                pq.push(c);
            }
        }
        // topological sort
        while(!pq.empty()){
            char ch=pq.top();
            pq.pop();
            ans+=ch;
            for(auto &q:mp[ch]){
                indegree[q-'a']--;
                if(indegree[q-'a']==0) pq.push(q);
            }
        }
        if(ans.size()!=st.size()){
            return "";
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends