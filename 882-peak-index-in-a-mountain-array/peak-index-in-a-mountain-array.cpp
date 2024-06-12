class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int peakElement = 0;
        int n=arr.size();
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if ((mid == n - 1 || arr[mid] > arr[mid + 1]) && (mid == 0 || arr[mid] > arr[mid - 1]))
            {      peakElement=arr[peakElement]>arr[mid]?peakElement:mid;
                break;
            }
            else if (arr[mid] < arr[mid + 1])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return peakElement;
    }
};