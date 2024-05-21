//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int crossOver(vector<int>arr,int low,int high,int x ){
        if(arr[high]<=x) return high;
        if(arr[low]>=x) return low;
        int mid=low+(high-low)/2;
        if(arr[mid]<=x && arr[mid+1]>x) return mid; 
        if(arr[mid] < x) return crossOver(arr,mid+1,high,x);
        return crossOver(arr,low,mid-1,x);
    }
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        vector<int>ans;
        int l=crossOver(arr,0,n-1,x);
        int r=l+1;
        int count=0;
        if(arr[l]==x) l--;
        while (l >= 0 && r < n && count < k) 
        { 
            if (x - arr[l] < arr[r] - x) 
                ans.push_back(arr[l--]); 
            else
                ans.push_back(arr[r++]); 
            count++; 
        } 
        while (count < k && l >= 0) {
            ans.push_back(arr[l--]);
            count++;
        }
        while(count<k && r<n){
            ans.push_back(arr[r++]);
            count++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends