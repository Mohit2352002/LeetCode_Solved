static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class MyHashMap {
    vector<list<pair<int,int>>>mp;
    size_t sz=10000;
public:
    MyHashMap() {
        mp.resize(sz);
    }
    
    void put(int key, int value) {
        int index=key%sz;
        auto &chain=mp[index];
        for(auto &it:chain){
            if(it.first==key){
                it.second=value;
                return;
            }
        }
        chain.emplace_back(key,value);
    }
    
    int get(int key) {
        auto &chain=mp[key%sz];
        if(chain.empty()) return -1;
        for(auto &it:chain){
            if(it.first==key) return it.second;
        }
        return -1;
    }
    
    void remove(int key) {
        auto &chain=mp[key%sz];
        //chain.remove_if([key](auto n) { return n.first == key; });        
        for(auto it=chain.begin();it!=chain.end();++it){
            if(it->first==key){
                chain.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */