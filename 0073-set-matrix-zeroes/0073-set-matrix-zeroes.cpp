class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<bool>rowMarker(m,false);
        vector<bool>colMarker(n,false);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    rowMarker[i]=true;
                    colMarker[j]=true;
                }
            }
        }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(rowMarker[i] || colMarker[j]){
                    matrix[i][j]=0;
                    }
                }
            }
        
    }
};