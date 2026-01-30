class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int left = 1,right = n-2;
        while(left<=right){
            int mid = left+(right-left)/2;
            //mid is peak checkin
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            //increasing slope /
            else if(nums[mid] > nums[mid-1]){ 
                left = mid+1;
            }
            //decreasing slope a[mid] > a[mid+1]  orr to make it correct for multiple case
            else{
                right = mid-1;
            }
        }
        return -1;
    }
};