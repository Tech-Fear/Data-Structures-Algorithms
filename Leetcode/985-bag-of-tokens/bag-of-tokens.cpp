class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score=0;
        int l=0,right=tokens.size()-1;
        while(l<=right){
            if(power>=tokens[l]){
                power-=tokens[l];
                l++,score++;
            }else if(tokens[l]>power && score>0 && l!=right){
                power+=tokens[right];
                right--,score--;
            }else{
                break;
            }
        }
        return score;
    }
};