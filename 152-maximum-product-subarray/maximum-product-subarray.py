class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        pref =1
        suff =1
        maxi = nums[0]

        for i in range(len(nums)):
            if pref == 0:
                pref = 1
            if suff == 0:
                suff = 1
            
            pref *= nums[i]
            suff *= nums[len(nums)-i-1]

            maxi = max(maxi, max(pref,suff))
        
        return maxi
        
        return prod