class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> avg(n,-1);
        int wdw = 2*k+1;
        long long sum = 0;

        if(wdw > n)return avg;

        for(int i=0;i<wdw;i++){
            sum += nums[i];
        }
        avg[k] = sum/wdw;

        for(int i=wdw;i<n;i++){
            sum += nums[i];
            sum -= nums[i-wdw];
            avg[i-k] = sum/wdw;
        }

        return avg;
    }
};