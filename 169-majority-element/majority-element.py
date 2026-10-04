class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        el = None
        cnt = 0

        for i in range(len(nums)):
            if(cnt == 0):
                cnt = 1
                el = nums[i]
            
            elif el == nums[i]:
                cnt += 1
            else:
                cnt -= 1
        
        return el
        