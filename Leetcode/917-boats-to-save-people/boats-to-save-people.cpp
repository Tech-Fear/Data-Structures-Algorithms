class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int count=0;
        int n=people.size();
        int curr=0;
        int left=0,right=n-1;
        while(left<=right){
            if(people[left]+people[right]<=limit){
                left++;
            }
            right--;
            count++;
        }
        return count;
    }
};