class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> res;
        int row=0,col=0;
        for(int i=0;i< n*m;i++){
            res.push_back(matrix[row][col]);
            if((row+col) % 2 == 0){
                //move up right
                if(col == m-1)row++;
                else if(row == 0)col++;
                else{
                    row--;
                    col++;
                }
            }
            else{
                //move down right
                if(row == n-1)col++;
                else if(col == 0)row++;
                else{
                    row++;
                    col--;
                }
            }
        }
        return res;
    }
};