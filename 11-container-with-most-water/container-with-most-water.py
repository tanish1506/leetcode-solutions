class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        area = 0
        maxi = 0
        n = len(height)
        i = 0
        j = n-1
        while(i<j):
            if(height[i] < height[j]):
                area = height[i] * (j-i)
                i += 1
                maxi = max(area,maxi)
            else:
                area = height[j] * (j-i)
                j -= 1
                maxi = max(area,maxi)
        
        return maxi


