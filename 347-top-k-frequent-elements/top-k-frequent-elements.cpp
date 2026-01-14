class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        vector<vector<int>> bucket(n+1);
        for(auto &p : freq){
            bucket[p.second].push_back(p.first);
        }

        vector<int> result;
        for(int i=bucket.size() - 1; i >=0 && result.size() < k;i--){
            for(int x : bucket[i]){
                result.push_back(x);
                if(result.size() == k) break;
            }
        }
        return result;
    }
};