class RandomizedSet {
    unordered_map<int,int>mp;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        bool flag=(mp.find(val)==mp.end());
        mp[val]=1;
        return flag;
    }
    
    bool remove(int val) {
        auto itr=mp.find(val);
        if(itr==mp.end()) return false;
        mp.erase(itr);
        return true;
    }
    int random_0_to_n(int n){
        return rand()%n;
    }
    int getRandom() {
        auto item=mp.begin();
        advance( item, random_0_to_n(mp.size()));
        return item->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */