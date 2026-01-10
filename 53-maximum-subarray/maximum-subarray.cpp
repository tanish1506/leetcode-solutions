class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long long maxSum = nums[0];
        long long currSum = 0;
        for(int i=0;i<n;i++){
            // currSum = max((long long)nums[i], currSum+nums[i]);
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxSum;
    }
};