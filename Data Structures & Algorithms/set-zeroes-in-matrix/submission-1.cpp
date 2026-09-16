class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        bool first=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!matrix[i][j]){
                    if(j==0){
                        first=true;
                    }else{
                        matrix[0][j]=0;
                    }
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(!matrix[0][0]){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }
        if(first){
            for(int j=0;j<n;j++){
                matrix[j][0]=0;
            }
        }
    }
};
