class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int baseSat = 0;
        int maxSat = 0;
        int maxi = 0;

        for(int i = 0;i<n;i++){
            if(grumpy[i] == 0){
                baseSat += customers[i];
            }
            if(grumpy[i] != 0){
                maxSat += customers[i];
            }
            if(i >= minutes){
                if(grumpy[i-minutes] == 1){
                    maxSat -= customers[i-minutes];
                }
            }
            maxi = max(maxi,maxSat);
        }
        return baseSat + maxi;
    }
};