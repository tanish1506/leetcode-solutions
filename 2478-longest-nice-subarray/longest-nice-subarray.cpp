class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left=0,mask=0,maxlen=0;
        for(int right=0;right<nums.size();right++){
            while((mask & nums[right]) != 0){
                mask ^= nums[left];
                left++;
            }
            mask |= nums[right];
            maxlen = max(maxlen,right-left+1);
        }
        return maxlen;
    }
};