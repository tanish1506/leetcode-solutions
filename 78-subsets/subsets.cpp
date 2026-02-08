class Solution {
public:
    void subs(int idx, vector<int> & nums,vector<int>&res,vector<vector<int>> & ans){
        int n = nums.size();
        if(idx == n){
            ans.push_back(res);
            return;
        }
        //include
        res.push_back(nums[idx]);
        subs(idx + 1, nums, res,ans);
        //exclude
        res.pop_back();
        subs(idx+1,nums,res,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        subs(0,nums,res,ans);
        return ans;
    }
};