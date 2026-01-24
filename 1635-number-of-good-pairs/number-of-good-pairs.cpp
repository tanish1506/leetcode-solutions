class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int i=0,count=0;
        while(i<n){
            for(int j=i+1;j<n;j++){
                if(nums[i] == nums[j] && i < j){
                    count++;
                }
            }
            i++;
        }
        return count;
    }
};