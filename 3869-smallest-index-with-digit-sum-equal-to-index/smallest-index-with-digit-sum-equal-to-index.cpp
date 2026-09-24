class Solution {
public:
    bool checksum(int val,int i){
        int sum=0;
        while(val != 0){
            int digit = val%10;
            sum += digit;
            val = val/10;
        }
        if(sum == i){
            return true;
        }else {
            return false;
        }
    }
    int smallestIndex(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
            if(checksum(nums[i],i)){
                return i;
            }
        }
        return -1;
    }
};