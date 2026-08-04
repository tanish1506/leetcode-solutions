class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX,maxi = INT_MIN;
        unordered_set<int> st;

        for(int i=0;i<nums.size();i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
            st.insert(nums[i]);
        }
        vector<int> ans;

        for(int i = mini+1;i<maxi;i++){
            if(!st.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};