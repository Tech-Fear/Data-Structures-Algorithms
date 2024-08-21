class Solution {
private:
    vector<int>binaryConv(int n){
        vector<int>bin;
        while(n>0){
            bin.push_back(n%2);
            n/=2;
        }
        reverse(bin.begin(),bin.end());
        return bin;
    }
public:
    int binaryGap(int n) {
       vector<int>binary=binaryConv(n);
       int best=0;
       for(int i=0;i<binary.size();i++){
            if(binary[i]==1){
                for(int j=i+1;j<binary.size();j++){
                    if(binary[j]==1){
                        best=max(best,j-i);
                        break;
                    }
                }
            }
       }
       return best;
    }
};