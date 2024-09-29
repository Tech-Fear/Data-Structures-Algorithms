class AllOne {
private:
    unordered_map<string, int> countMap;
    unordered_map<int, list<string>> freqMap;
    int maxFreq;
    int minFreq;

public:
    AllOne() : maxFreq(0), minFreq(0) {}

    void inc(const string& key) {
        int currentFreq = countMap[key];

        if (currentFreq > 0) {
            freqMap[currentFreq].remove(key);
            if (freqMap[currentFreq].empty()) {
                freqMap.erase(currentFreq);
                if (minFreq == currentFreq) {
                    minFreq++;
                }
            }
        }

        countMap[key]++;
        int newFreq = countMap[key];
        freqMap[newFreq].push_back(key);
        if (newFreq > maxFreq) {
            maxFreq = newFreq;
        }
        if (minFreq == 0 || newFreq < minFreq) {
            minFreq = newFreq;
        }
    }

    void dec(const string& key) {
        if (countMap[key] > 0) {
            int currentFreq = countMap[key];
            freqMap[currentFreq].remove(key);
            if (freqMap[currentFreq].empty()) {
                freqMap.erase(currentFreq);
                if (maxFreq == currentFreq) {
                    maxFreq--;
                }
                if (minFreq == currentFreq) {
                    minFreq = freqMap.empty() ? 0 : freqMap.begin()->first;
                }
            }

            countMap[key]--;
            if (countMap[key] > 0) {
                freqMap[countMap[key]].push_back(key);
                if (minFreq > countMap[key]) {
                    minFreq = countMap[key];
                }
            } else {
                countMap.erase(key);
            }
        }
    }

    string getMaxKey() {
        if (maxFreq == 0) return "";
        return freqMap[maxFreq].back();
    }

    string getMinKey() {
        if (minFreq == 0) return "";
        return freqMap[minFreq].front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */