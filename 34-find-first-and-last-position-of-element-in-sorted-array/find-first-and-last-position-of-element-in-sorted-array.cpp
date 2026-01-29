class Solution {
public:
    
    int first(vector<int>& nums, int target){
        int left=0,right=nums.size()-1;
        int fstIdx=-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                fstIdx = mid;
                right = mid-1;
            }
            else if(nums[mid] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return fstIdx;
    }
    int last(vector<int>& nums, int target){
        int left = 0,right=nums.size()-1;
        int lstIdx = -1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                lstIdx = mid;
                left = mid+1;
            }
            else if(nums[mid] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return lstIdx;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target) , last(nums,target)};
    }
};