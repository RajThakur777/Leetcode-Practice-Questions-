class MapSum {
public:
    map<string , int> mpp;

    bool isMatch(string prefix , string str) {
        for(int i=0; i<prefix.size(); i++) {
            if(str[i] != prefix[i]) {
                return false;
            }
        }
        return true;
    }

    MapSum() {    
    }
    
    void insert(string key, int val) {
        mpp[key] = (val);
    }
    
    int sum(string prefix) {
        int ans = 0;

        for(auto it : mpp) {
            if(isMatch(prefix , it.first)) {
                ans += it.second;
            }
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */