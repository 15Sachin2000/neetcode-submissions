class LRUCache {
public:
list<pair<int,int>> l;
unordered_map<int,list<pair<int,int>>::iterator> mp;
int s;
    LRUCache(int capacity) {
        s=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        int val=mp[key]->second;
        l.erase(mp[key]);
        l.push_back({key,val});
        mp[key]=--l.end();
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
        l.erase(mp[key]);
        l.push_back({key,value});
        mp[key]=--l.end();
        }else if(l.size()==s){
            auto itr=l.front();
            l.pop_front();
            l.push_back({key,value});
            mp.erase(itr.first);
            mp[key]=--l.end();
        }else{
           l.push_back({key,value});
            mp[key]=--l.end(); 
        }
    }
};
