class TimeMap {
public:
    unordered_map<string,pair<string,int>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // if(mp.find(key)!= mp.end()){
        //     mp[key].push({value,timestamp});
        // }else{
            // mp[key]=[{value,timestamp}];
            mp[key]={value,timestamp};
        // }
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)!=mp.end() && mp[key].second<=timestamp){
            return mp[key].first;
        }
        return "";
    }
};
