class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            if(x == first || x == second || x == third) continue;

            if(x > first){
                third = second;
                second = first;
                first = nums[i];
            }
            else if( x > second  ){
                third = second;
                second = nums[i];
            }   
            else if(x > third){
                third = x;
            }
            
        }
        return (third == LLONG_MIN) ? first : third;
    }
};