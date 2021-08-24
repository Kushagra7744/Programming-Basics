class LRUCache {
public:
    
    int max_cap;
    unordered_map<int,list<pair<int,int>>::iterator > umap;
    list<pair<int,int>>l;
    
    LRUCache(int capacity) {
        max_cap = capacity;
    }
    
    int get(int key) {
        if(umap .find(key) == umap.end()){
            return -1;
        }
        else{
            int val = umap[key]->second;
            l.erase(umap[key]);
            umap.erase(key);
            l.push_front(make_pair(key,val));
            umap[key] = l.begin();
            return val;
        }
    }
    
    void put(int key, int value) {
        if(umap.find(key) != umap.end()){
            l.erase(umap[key]);
            umap.erase(key);
        }
        if(l.size() >= max_cap){
            int k = l.back().first;
            l.pop_back();
            umap.erase(k);
        }
        
        l.push_front(make_pair(key,value));
        umap[key]=l.begin();
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
