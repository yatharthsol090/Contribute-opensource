class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    
    TimeMap() {
        string key;
        string value;
        int timestamp;
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) {
            return "";
        }
        
        if(timestamp < mp[key][0].first) {
            return "";
        }
        
        int low = 0, high = mp[key].size();
        
        while(high > low) {
            int mid = (low + high)/2;
            if(mp[key][mid].first <= timestamp) low = mid+1;
            else high = mid;
        }
        if(high == 0) return "";
        return mp[key][high-1].second;
    }
};
