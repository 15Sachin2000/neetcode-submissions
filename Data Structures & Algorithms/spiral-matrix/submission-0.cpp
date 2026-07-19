class Solution {
public:
    bool isBaseTrue(int sr,int sc,int er,int ec){
        return sr<=er && sc<=ec;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int sr=0,sc=0,er=n-1,ec=m-1;
        vector<int> ans;
        while(isBaseTrue(sr,sc,er,ec)){
            if(isBaseTrue(sr,sc,er,ec)){
                int i=sc;
                while(i<=ec){
                    ans.push_back(matrix[sr][i]);
                    i++;
                }
                sr++;
            }
            if(isBaseTrue(sr,sc,er,ec)){
                int i=sr;
                while(i<=er){
                    ans.push_back(matrix[i][ec]);
                    i++;
                }
                ec--;
            }
            if(isBaseTrue(sr,sc,er,ec)){
                int i=ec;
                while(i>=sc){
                    ans.push_back(matrix[er][i]);
                    i--;
                }
                er--;
            }
            if(isBaseTrue(sr,sc,er,ec)){
                int i=er;
                while(i>=sr){
                    ans.push_back(matrix[i][sc]);
                    i--;
                }
                sc++;
            }
        }
        return ans;
    }
};
