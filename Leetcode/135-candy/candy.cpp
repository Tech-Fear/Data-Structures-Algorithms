class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int i=1,candy=n;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                i++;continue;
            }
            int peak=0;
            while(ratings[i]>ratings[i-1]){
                peak++;
                candy+=peak;
                i++;
                if(i==n) return candy;
            }
            int val=0;
            while(i<n && ratings[i]<ratings[i-1]){
                val++;
                candy+=val;
                i++;
            }
            candy-=min(peak,val);
        }
        return candy;
    }
};