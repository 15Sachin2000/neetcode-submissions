class Solution {
public:
    int findRoot(int i,vector<int> &p){
        if(p[i]==i){
            return i;
        }
        p[i]=findRoot(p[i],p);
        return p[i];
    }
    void unionEdges(int a,int b,vector<int> &p,vector<int> &s){
        if(s[b]>s[a]){
            swap(a,b);
        }
        p[b]=a;
        s[a]+=s[b];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int> parent(n);
        vector<int> size(n,1);
        for(int i=1;i<n;i++){
            parent[i]=i;
        }
        for(vector<int> v:edges){
            int root1=findRoot(v[0],parent);
            int root2=findRoot(v[1],parent);
            if(root1 == root2){
                return v;
            }
            unionEdges(root1,root2,parent,size);
        }
        return {};
    }
};
