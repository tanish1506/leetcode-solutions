class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res(candies.size());
        int max = 0;
        for(int i=0;i<candies.size();i++){
            if(max < candies[i]){
                max = candies[i];
            }
        }
        for(int i=0;i<candies.size();i++){
            int extra = candies[i] + extraCandies;
            if(extra >= max){
                res[i] = true;
            }
        }
        return res;
    }
};