class LRUCache{
public:
    LRUCache(int capacity) {
        hash.clear();
        lru.clear();
        rem = capacity;
    }
        int get(int key) {
        if (hash.count(key) == 0) return -1;
        int value = hash[key]->second;
        lru.erase(hash[key]);
        lru.push_front(make_pair(key, value));
        hash[key] = lru.begin();
        return value;
    }
        void set(int key, int value) {
        if (hash.count(key) > 0) {
            lru.erase(hash[key]);
            rem ++;
        }
        if (rem == 0){
            hash.erase(lru.back().first);
            lru.pop_back();
            rem ++;
        }
        rem --;
        lru.push_front(make_pair(key, value));
        hash[key] = lru.begin();
    }
private:
    int rem;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
};