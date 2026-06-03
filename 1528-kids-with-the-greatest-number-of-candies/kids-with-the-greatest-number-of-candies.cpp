class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies){
        vector<bool> res(candies.size());
        int maxi=0;
        for(int i=0;i<candies.size();i++){
            maxi = max(maxi,candies[i]);
        }
        for(int i=0;i<candies.size();i++){
            int extra = candies[i]+extraCandies;
            if( extra >= maxi){
                res[i] = true;
            }
        }
        return res;
    }
};