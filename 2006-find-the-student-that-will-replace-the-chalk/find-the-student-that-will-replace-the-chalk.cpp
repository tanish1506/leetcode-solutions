class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = 0;
        for(int x : chalk){
            total += x;
        }
        k %= total;

        for(int i=0;i<chalk.size();i++){
            if(chalk[i] > k){
                return i;
            }

            k -= chalk[i];
        }
        return 0;
    }
};