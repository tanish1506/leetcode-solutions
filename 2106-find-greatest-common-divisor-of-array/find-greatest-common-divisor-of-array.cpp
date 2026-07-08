class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = nums[0],maxi = 0;
        for(int i=0;i<nums.size();i++){
            if(mini >= nums[i]) mini = nums[i];

            if(maxi <= nums[i]) maxi = nums[i];
        }
        int gcd=1;
        for(int i = min(mini,maxi); i>=1;i--){
            if(mini%i == 0 && maxi%i == 0){
                return i;
            }
        }
        return gcd;
    }
};