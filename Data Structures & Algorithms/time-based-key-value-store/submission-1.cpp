class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mp;
    TimeMap() {
        
    }
    
    static bool cmp(pair<string,int> &a,pair<string,int> &b){
        return a.second<=b.second;
    }

    void set(string key, string value, int timestamp) {
        // if(mp.find(key)== mp.end()){
            mp[key].push_back({value,timestamp});
        // }else{
        //     mp[key]=[{value,timestamp}];
        //     // mp[key]={value,timestamp};
        // }
    }
    
    string get(string key, int timestamp) {
       if(mp.find(key)==mp.end()){
        return "";
       }
       int n=mp[key].size();
       int l=0,r=n-1,ans=INT_MAX;
       while(l<=r){
        int mid=l+(r-l)/2;
        if(mp[key][mid].second<=timestamp){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
       }
       if(ans==INT_MAX){
        return "";
       }
       return mp[key][ans].first;
    }
};
