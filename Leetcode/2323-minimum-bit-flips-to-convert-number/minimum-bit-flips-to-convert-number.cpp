class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<32>dec1(start);
        bitset<32>dec2(goal);
        int count=0;
        for(int i=0;i<32;i++){
            if(dec2[i]!=dec1[i]) count++;
        }
        return count;
    }
};