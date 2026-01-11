class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n= nums.size();
        int lftSum = 0, sum=0,rgtS;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }

        for(int i=0;i<n;i++){
            rgtS = sum - lftSum -nums[i];
            if( lftSum == rgtS){
                return i;
            }
            lftSum += nums[i];
        }
        return -1;
    }
};