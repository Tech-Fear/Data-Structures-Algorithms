class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

        int n = books.size();

        vector<int> ans(n+1,INT_MAX);

        ans[0] = 0;


        for(int i=1;i<=n;i++){

            int w = books[i-1][0];
            int h = books[i-1][1];

            ans[i] = ans[i-1] + h;

            for(int j = i-1; j>0 ;j--){

                if( w + books[j-1][0] <= shelfWidth){

                    h = max(h, books[j-1][1]);
                    w += books[j-1][0];
                    ans[i] = min(ans[i], ans[j-1]+h);
                    
                }else break;
                
            }
            
        }

        return ans[n];
        
    }
};