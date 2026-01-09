class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int n=nums.size();
        int l=0,r=0,count=0;
        long long prod=1;
        while(r<n){
            prod *= nums[r];

            while(prod >= k){
                prod /= nums[l];
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
};