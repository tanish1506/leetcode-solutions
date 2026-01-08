class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> avg(n,-1);

        int windowsize = 2*k+1;
        if(windowsize > n) return avg;

        long long sum = 0;
        for(int i=0;i<windowsize;i++){
            sum += nums[i];
        }

        avg[k] = sum/windowsize;

        for(int i=windowsize;i<n;i++){
            sum += nums[i];
            sum -= nums[i - windowsize];
            avg[i-k] = sum/windowsize;
        }
        return avg;
    }
};