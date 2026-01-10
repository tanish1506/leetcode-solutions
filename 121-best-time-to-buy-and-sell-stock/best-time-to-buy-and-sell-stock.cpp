class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> bestBuy(n);
        bestBuy[0] = INT_MAX;
        for(int i=1;i<n;i++){
            bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
        }
        int maxP = 0;
        for(int i=0;i<n;i++){
            int currp = prices[i] - bestBuy[i];
            maxP = max(maxP,currp);
        }
    return maxP;
    }
};