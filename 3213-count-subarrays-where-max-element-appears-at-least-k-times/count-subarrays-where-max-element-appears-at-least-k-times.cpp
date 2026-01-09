class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int r=0,l=0,maxf = 0;
        long long cnt=0;
        int n=nums.size();
        int mx = *max_element(nums.begin(),nums.end());

        while(r<nums.size()){
            if(nums[r] == mx){
                maxf++;
            }
            while(maxf >= k){
                cnt += n-r;
                if(nums[l] == mx){
                    maxf--;
                }
                l++;
            }
            r++;
        }
        return cnt;
    }
};