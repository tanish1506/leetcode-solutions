class Solution {
public:
    int atmost(vector<int>& nums,int bound){
        int count=0;
        int len = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <= bound){
                len++;
            }else{
                len = 0;
            }
            count += len;
        }
        return count;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return atmost(nums,right) - atmost(nums,left-1);
        
    }
};