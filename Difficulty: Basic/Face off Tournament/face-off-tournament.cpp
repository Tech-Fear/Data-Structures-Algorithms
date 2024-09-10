//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to determine the winner based on divisible counts
    string winner(vector<int> &arr, int m, int n) {
        // Code here
        int Ram = 0;
        int rohan = 0;
        int i = 0;
        while(i<arr.size())
        {
             
            if(arr[i]%m==0){
                Ram++;
            }
            if(arr[i]%n==0){
                rohan++;
            }
            i++;
        }
        if(Ram==rohan)
        {
            return "Both";
        }
        if(Ram>rohan){
            return "Ram";
        }
        else 
        return "Rohan";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int m, n;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        ss >> m;
        ss >> n;

        Solution obj;
        cout << obj.winner(arr, m, n) << endl;
    }
    return 0;
}
// } Driver Code Ends