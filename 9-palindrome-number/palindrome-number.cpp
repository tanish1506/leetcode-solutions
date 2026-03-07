class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int org = x;
        long long temp = 0;

        while(x > 0){
            temp = temp * 10 + x % 10;
            x /= 10;
        }
        if(org == temp) return true;

        return false;
    }
};