class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0,digit=0;
        
        for(int i=0;i<nums.size();i++){
            int n = nums[i];

            while(n>0){
                n = n/10;
                digit++;
            }

            if(digit%2==0){
                count++;
            }
            digit=0;
        }
        return count;
    }
};