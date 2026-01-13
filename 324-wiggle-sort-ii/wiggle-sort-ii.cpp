class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());
        int n = nums.size();
        int left= (n-1)/2;
        int right = n-1;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                nums[i] = sorted[left--];
            }else{
                nums[i] = sorted[right--];
            }
        }
    }
};