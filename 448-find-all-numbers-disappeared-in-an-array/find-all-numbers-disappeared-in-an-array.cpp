class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n,0);
        for(int x : nums){
            temp[x-1]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(temp[i] == 0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};