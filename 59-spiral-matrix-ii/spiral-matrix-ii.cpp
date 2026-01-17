class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int val=1;
        int left=0,right=n-1;
        int top=0,bottom=n-1;
        vector<vector<int>> res(n,vector<int> (n));
        while(top<=bottom && left<=right){
            //right
            for(int i=left;i<=right;i++){
                res[top][i] = val;
                val++;
            }
            top++;

            //bottom
            for(int i=top;i<=bottom;i++){
                res[i][right] = val;
                val++;
            }
            right--;

            if(top<=bottom){

                //left
                for(int i=right;i>=left;i--){
                    res[bottom][i] = val;
                    val++;
                }
                bottom--;
            }
            if(left<=right){
                //up
                for(int i=bottom;i>=top;i--){
                    res[i][left] = val;
                    val++;
                }
                left++;
            }
        }
        return res;
    }
};