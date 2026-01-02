class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int left = 0;
        int right = n-1;
        int pos = n-1;

        while(left <= right){
            int lftsq = nums[left] * nums[left];
            int rgtsq = nums[right] * nums[right];

            if(lftsq > rgtsq){
                ans[pos] = lftsq;
                left++;
            }
            else{
                ans[pos] = rgtsq;
                right--;
            }
            pos--;
        }
        return ans;
    }
};