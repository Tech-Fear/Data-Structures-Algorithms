//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int ngsr(long double dist, vector<int>& arr) {
    int n = arr.size();
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = static_cast<int>((arr[i] - arr[i - 1]) / dist);
        if (fabs(static_cast<long double>(arr[i] - arr[i - 1])) == dist * numberInBetween) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

double findSmallestMaxDist(vector<int>& stations, int k) {
    int n = stations.size();
    long double low = 0, high = 0;
    for (int i = 0; i < n - 1; i++) {
        high = max(high, static_cast<long double>(stations[i + 1] - stations[i]));
    }
    long double diff = 1e-9;
    while (high - low > diff) {
        long double mid = (low + high) / 2.0;
        int cnt = ngsr(mid, stations);
        if (cnt > k) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return round(high*100)/100.0;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends