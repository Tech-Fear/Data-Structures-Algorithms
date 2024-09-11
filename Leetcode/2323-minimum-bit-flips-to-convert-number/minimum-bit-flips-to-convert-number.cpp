class Solution {
    int bit(int num,int i){
        if(num&(1<<(i-1))) return 1;
        return 0;
    }
public:
    int minBitFlips(int start, int goal) {
        /* Approch 1 using STL: 
        bitset<32>dec1(start);
        bitset<32>dec2(goal);
        int count=0;
        for(int i=0;i<32;i++){
            if(dec2[i]!=dec1[i]) count++;
        }
        return count;
        */
        //Approch 2 
        // int count=0;
        // for(int i=1;i<32;i++){
        //     if(bit(start,i) ^ bit(goal,i)) count++; //This can also be if(!(bit(start,i)&bit(goal,i))) count++;
        // }
        // return count;
        
        // Approch 3 
        return __builtin_popcount(start^goal);
    }
};