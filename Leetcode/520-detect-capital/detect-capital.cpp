class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (n == 1) return true;

        bool firstCapital = isupper(word[0]);
        bool secondCapital = (n > 1) && isupper(word[1]);
        if(firstCapital && (secondCapital)){
            for(int i=2;i<n;i++){
                if(!isupper(word[i])) return false;
            }
            return true;
        }
        if(firstCapital && !secondCapital){
            for(int i=2;i<n;i++){
                if(isupper(word[i])) return false;
            }
            return true;
        }
        if(!firstCapital){
            for(int i=1;i<n;i++){
                if(isupper(word[i])) return false;
            }
            return true;
        }
        return false;
    }
};
