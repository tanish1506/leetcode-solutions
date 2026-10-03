class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        seen = {}

        for i,num in enumerate(nums):
            n = target-num
            if n in seen:
                return [seen[n],i]
            seen[num] = i

        return []