class Solution {
public:
    int findRoot(int i,vector<int> &p){
        if(p[i]==i){
            return i;
        }
        return findRoot(p[i],p);
    }
    // void unionEdges(int a,int b,vector<int> &p){
    //     if(pa)
    // }
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
            cout<<root1<<" "<<root2<<endl;
            if(root1 == root2){
                return v;
            }
            if(size[root1]>size[root2]){
                parent[root2]=root1;
                size[root1]+=size[root2];
            }else{
                parent[root1]=root2;
                size[root2]+=size[root1];
            }
        }
        return {};
    }
};
