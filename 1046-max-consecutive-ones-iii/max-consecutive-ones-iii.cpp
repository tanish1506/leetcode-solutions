class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0;
        int len=0,zero=0;
        int l=0;
        int r=0;
        while(r<n){
            if(nums[r] == 0) zero++;

            while(zero > k){
                if(nums[l] == 0) zero--;
                l++;
            }
            if(zero <= k){
                len = r-l+1;
                maxlen = max(maxlen,len);
            }
            r++;
        }
        return maxlen;
    }
};