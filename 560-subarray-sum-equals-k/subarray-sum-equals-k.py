class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        mpp = {0:1}
        

        prefS = 0
        cnt = 0

        for i in range(len(nums)):
            prefS += nums[i]
            remove = prefS - k
            cnt += mpp.get(remove,0)
            mpp[prefS] = mpp.get(prefS,0) + 1

        return cnt