class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        long long maxSum = sum;
        for(int i = k ;i<n;i++){
            sum += nums[i];     //add new element by sliding
            sum -= nums[i-k];   // remove the starting elemet i.e the old 

            maxSum = max(maxSum,sum);
        }
        return (double)maxSum/k;
    }
};