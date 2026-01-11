class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum=0,minLen = INT_MAX,j=0;

        for(int i=0;i<n;i++){
            sum += nums[i];
            while(sum >= target){
                minLen = min(minLen, i-j+1);
                sum -= nums[j];
                j++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};