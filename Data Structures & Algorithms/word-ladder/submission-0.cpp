class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n);
        queue<int> q;
        for(int i=0;i<n;i++){
            string a=wordList[i];
            int beginDiff=0;
            for(int j=0;j<a.size();j++){
                if(a[j]!=beginWord[j]){
                    beginDiff++;
                }
            }
            if(beginDiff==1){
                vis[i]=true;
                q.push(i);
            }
            for(int j=i+1;j<n;j++){
                int diff=0;
                string b=wordList[j];
                for(int k=0;k<a.size();k++){
                    if(a[k]!=b[k]){
                        diff++;
                    }
                }
                if(diff==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=1;
        while(!q.empty()){
            ans++;
            int s=q.size();
            for(int i=0;i<s;i++){
                int qidx=q.front();
                q.pop();
                if(endWord==wordList[qidx]){
                    return ans;
                }
                for(int j:adj[qidx]){
                    if(!vis[j]){
                        vis[j]=true;
                        q.push(j);
                    }
                }
            }
        }
        return 0;
    }
};
