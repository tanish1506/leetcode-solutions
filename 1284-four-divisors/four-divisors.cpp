class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int sum = 0;
            int count=0;
            for(int j=1; j*j <= num;j++){
                if(num % j == 0){
                    int d1 = j;
                    int d2 = num/j;
                    if(d1==d2){
                        count++;
                        sum += d1;
                    }else{
                        count += 2;
                        sum+= d1 + d2;
                    }
                }
            }
            if(count == 4){
                totalSum += sum;
            }
            
        }
        return totalSum;
    }
};