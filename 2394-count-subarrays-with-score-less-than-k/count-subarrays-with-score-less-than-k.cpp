class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int r=0,l=0;
        long long sum=0,cnt=0;
        while(r<nums.size()){
            sum += nums[r];

            while(sum * (r-l+1) >= k){
                sum -= nums[l];
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
};