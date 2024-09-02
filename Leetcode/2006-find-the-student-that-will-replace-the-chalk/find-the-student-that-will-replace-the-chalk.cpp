class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(auto &s:chalk){
            sum+=s;
        }
        int z=k%sum;
        for(int i=0;i<chalk.size();i++){
            if(chalk[i]>z){
                return i;
            }
            z-=chalk[i];
        }
        return 0;
    }
};