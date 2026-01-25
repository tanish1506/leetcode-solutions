class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0,totalCost = 0;
        for(int g : gas){
            totalGas += g;
        }
        for(int c : cost){
            totalCost += c;
        }

        if(totalGas < totalCost){
            return -1;
        }

        //uniques solution
        int currGas=0,start = 0;
        for(int i=0;i<n;i++){
            currGas += (gas[i] - cost[i]);
            if(currGas < 0){
                start = i+1;
                currGas = 0;
            }
        }

        return start;

    }
};