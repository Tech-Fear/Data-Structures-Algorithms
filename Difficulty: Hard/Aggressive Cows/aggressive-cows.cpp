//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:    
    bool isValid(vector<int>&stalls,int mid,int n,int k){
        int prev=stalls[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(stalls[i]-prev>=mid){
                count++;
                prev=stalls[i];
            }
            if(count==k) return true;
        }
        return false;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int min=1,result;
        int max=(stalls[n-1]-stalls[0])/(k-1);
        while(min<=max){
            int mid=min+(max-min)/2;
            if(isValid(stalls,mid,n,k)){
                result=mid;
                min=mid+1;
            }else{
                max=mid-1;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends