class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        
        int small = *min_element(nums.begin(),nums.end());
        int large = *max_element(nums.begin(),nums.end());
        
        for(int i=small;i>0;i--){
            if(small % i == 0 && large % i == 0){
                return i;
            }
        }

        return 1;
    }
};