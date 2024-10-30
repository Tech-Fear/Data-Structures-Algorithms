class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int cur=capacity;
        int steps=0;
        for(int i=0;i<plants.size();i++){
            if(cur<plants[i]){
                steps += i * 2;
                cur = capacity;
            }
            cur -= plants[i];
            steps++;
        }
        return steps;
    }
};