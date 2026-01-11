class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int l=0,maxf=0,ans=0;
        for(int r=0;r<n;r++){
            mp[nums[r]]++;
            maxf = max(maxf , mp[nums[r]]);

            while((r-l+1) - maxf > k){
                mp[nums[l]]--;
                l++;
            }
            ans = max(ans,maxf);
        }
        return ans;
    }
};