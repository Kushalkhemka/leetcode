class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose the matrix
        int n=matrix.size(); //sq matrix 
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]); //swapping inplace
            }
        }
        
        //now time to reverse all the arrays
        for(int k=0;k<n;k++){ //reverse all rows 
            int l=0;int m=n-1; 
            while(l<m){
                swap(matrix[k][l],matrix[k][m]);
                l++;m--;
            }
        }
    }
};