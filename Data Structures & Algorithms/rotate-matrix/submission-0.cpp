class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n=m.size();
        int i=0,j=n-1;
        while(i<j){
            for(int k=0;k<n;k++){
                swap(m[k][i],m[k][j]);
            }
            i++;
            j--;
        }
        for(vector<int> v:m){
            for(int y:v)cout<<y<<" ";
            cout<<endl;
        }
        i=0,j=n-1;
        while(j>=0 && i<n){
        int k=1;
        while(j-k>=0 && i+k<n){
            swap(m[i][j-k],m[i+k][j]);
            k++;
        }
        i++;
        j--;
        }
        cout<<endl<<endl;
        for(vector<int> v:m){
            for(int y:v)cout<<y<<" ";
            cout<<endl;
        }
    }
};
