class Solution {
public:
    int findParent(vector<int>&parent,int i){
        if(parent[i]==i){
            return i;
        }
        return findParent(parent,parent[i]);
    }
    void unions(vector<int> &parent,int a,int b,vector<int> &size){
        int pa=findParent(parent,a);
        int pb=findParent(parent,b);
        if(size[pa]<size[pb]){
            unions(parent,b,a,size);
        }else{
            parent[pb]=pa;
            size[pa]+=size[pb];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1);
        vector<int> size(n+1,1);
        for(int i=1;i<=n;i++) parent[i]=i;
        for(vector<int> v:edges){
            int pa=findParent(parent,v[0]);
            int pb=findParent(parent,v[1]);
            if(pa==pb){
                return v;
            }
            unions(parent,pa,pb,size);
        }
        return {};
    }
};
