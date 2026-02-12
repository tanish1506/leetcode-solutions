class Solution {
public:
void findComb(int idx,vector<int> &arr,int target,vector<int> & curr, vector<vector<int>> &ans){
    if(idx == arr.size()){
        if(target == 0){
            ans.push_back(curr);
        }
        return;
    }
    //pick
    if(arr[idx] <= target){
        curr.push_back(arr[idx]);
        findComb(idx,arr,target-arr[idx],curr,ans);
        curr.pop_back();
    }
    //not pick
    findComb(idx+1,arr,target,curr,ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        findComb(0,candidates,target,curr,ans);
        return ans;
    }
};