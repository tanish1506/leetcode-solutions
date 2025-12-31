class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int temp=0,sum=0;
        int m = accounts.size();
        for(int i=0;i<m;i++){
            int n = accounts[i].size();
            for(int j=0;j<n;j++){
                sum += accounts[i][j];
            }
            if(temp <= sum){
                temp = sum;
            }
            sum=0;
        }
        return temp;
    }
};