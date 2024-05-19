//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        if (k <= arr[0]) return arr[0];
    if (k >= arr[n-1]) return arr[n-1];

    int left = 0, right = n-1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == k) return arr[mid];

        if (arr[mid] < k) {
            if (mid < n - 1 && arr[mid + 1] > k) {
                int diffMid = abs(arr[mid] - k);
                int diffMidNext = abs(arr[mid + 1] - k);
                if (diffMid == diffMidNext) {
                    return arr[mid + 1];
                }
                return (diffMid < diffMidNext) ? arr[mid] : arr[mid + 1];
            }
            left = mid + 1;
        } else {
            if (mid > 0 && arr[mid - 1] < k) {
                int diffMid = abs(arr[mid] - k);
                int diffMidPrev = abs(arr[mid - 1] - k);
                if (diffMid == diffMidPrev) {
                    return arr[mid];
                }
                return (diffMid < diffMidPrev) ? arr[mid] : arr[mid - 1];
            }
            right = mid - 1;
        }
    }

    if (left > 0 && left < n - 1) {
        int diffLeft = abs(arr[left] - k);
        int diffLeftPrev = abs(arr[left - 1] - k);
        int diffLeftNext = abs(arr[left + 1] - k);

        if (diffLeft == diffLeftPrev && diffLeft == diffLeftNext) {
            return std::max(arr[left], std::max(arr[left - 1], arr[left + 1]));
        } else if (diffLeft == diffLeftPrev) {
            return std::max(arr[left], arr[left - 1]);
        } else if (diffLeft == diffLeftNext) {
            return std::max(arr[left], arr[left + 1]);
        } else {
            if (diffLeft < diffLeftPrev && diffLeft < diffLeftNext) {
                return arr[left];
            } else if (diffLeftPrev <= diffLeftNext) {
                return arr[left - 1];
            } else {
                return arr[left + 1];
            }
        }
    }

    return arr[left];
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends