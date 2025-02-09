class NumberContainers {
public:
    unordered_map<int, int> mpIndexToNum;
    unordered_map<int, set<int>> mpNumToIndices;
    
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (mpIndexToNum.find(index) != mpIndexToNum.end()) {
            int oldNumber = mpIndexToNum[index];
            mpNumToIndices[oldNumber].erase(index);
            if (mpNumToIndices[oldNumber].empty()) {
                mpNumToIndices.erase(oldNumber);
            }
        }
        
        mpIndexToNum[index] = number;
        mpNumToIndices[number].insert(index);
    }
    
    int find(int number) {
        if (mpNumToIndices.find(number) != mpNumToIndices.end() && !mpNumToIndices[number].empty()) {
            return *mpNumToIndices[number].begin();
        }
        return -1;
    }
};
/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index, number);
 * int param_2 = obj->find(number);
 */
