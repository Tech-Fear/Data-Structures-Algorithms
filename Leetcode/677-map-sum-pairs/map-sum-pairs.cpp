class MapSum {
public:
    unordered_map<string,int>mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key]=val;
    }
    
    int sum(string prefix) {
        int s=0;
        int prefixl=prefix.length();
        for(auto &m:mp){
            string key=m.first;
            key=key.substr(0,prefixl);
            if(key==prefix){
                s+=m.second;
            }
        }
        return s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */