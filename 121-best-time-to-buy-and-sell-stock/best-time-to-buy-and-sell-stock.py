class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        minprofit = prices[0]
        maxprofit = 0;
        for i in range(0,len(prices)):
            minprofit = min(minprofit , prices[i]);

            maxprofit = max(maxprofit, prices[i] - minprofit);

        
        return maxprofit
