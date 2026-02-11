class Solution {
public:
    void findComb(int idx,vector<int> &nums,int target, vector<int> &curr, vector<vector<int>> & ans){
        if(idx == nums.size()){
            if(target == 0){
                ans.push_back(curr);
            }
            return;
        }

        //pick the element
        if(nums[idx] <= target){
            curr.push_back(nums[idx]);
            findComb(idx,nums,target - nums[idx],curr, ans);
            curr.pop_back();
        }
        findComb(idx+1,nums,target,curr,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        findComb(0,candidates,target,curr,ans);
        return ans;
    }
};