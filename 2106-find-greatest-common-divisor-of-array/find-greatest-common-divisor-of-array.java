class Solution {
    public int findGCD(int[] nums) {
        int small = nums[0];
        int large = nums[0];

        
        for (int num : nums) {
            if (num < small) small = num;
            if (num > large) large = num;
        }

        
        for (int i = small; i > 0; i--) {
            if (small % i == 0 && large % i == 0) {
                return i;
            }
        }

        return 1;
    }
}