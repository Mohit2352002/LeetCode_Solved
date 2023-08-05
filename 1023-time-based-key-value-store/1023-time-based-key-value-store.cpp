 static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class TimeMap {
    map<int,unordered_map<string,string>>timeMaper;//Time->{Key->Value}
    map<string,set<int>>keyUpdates;//Key->Time

public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        timeMaper[timestamp][key]=value;
        keyUpdates[key].insert(timestamp);
    }
    
    string get(string key, int timestamp) {
        if(keyUpdates[key].empty()) return "";
        else if(*(keyUpdates[key].lower_bound(timestamp))==timestamp) 
            return timeMaper[*keyUpdates[key].lower_bound(timestamp)][key];
        else if(keyUpdates[key].lower_bound(timestamp)!=keyUpdates[key].begin())
            return timeMaper[*prev(keyUpdates[key].lower_bound(timestamp))][key];
        else return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */