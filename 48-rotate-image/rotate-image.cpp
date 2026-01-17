class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        //transpose
        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //swap the column from first and last;
        for(int i=0;i<n;i++){
            int j=0,k=m-1;
            while(j<k){
                swap(matrix[i][j++] , matrix[i][k--]);
            }
        }


    }
};