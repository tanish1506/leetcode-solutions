class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;

        int org = x;
        long temp = 0;

        while (x > 0) {
            temp = temp * 10 + x % 10;
            x /= 10;
        }

        return org == temp;
    }
}