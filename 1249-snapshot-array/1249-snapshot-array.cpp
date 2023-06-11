class SnapshotArray {
    int count=0;
    unordered_map<int,map<int,int>>mp; // index->{snap_id->val}
public:
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        mp[index][count]=val;
    }
    
    int snap() {
        return count++;
    }
    
    int get(int index, int snap_id) {
        //if(mp[index].empty() || snap_id < mp[index].begin()->first)return 0;
        auto it = mp[index].lower_bound(snap_id);
        if(!mp[index].empty() and it == mp[index].end()){
            it--;
            return it->second;
        }
        if(it->first==snap_id) return it->second;
        return it == begin(mp[index]) ? 0 : (--it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */