class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    long long hour(vector<int>& piles, int h){
        long long total = 0;
        for(int i=0;i<piles.size();i++){
            total += (piles[i] + h - 1)/h;
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1,right = findMax(piles);
        while(left<=right){
            int mid = left+(right-left)/2;
            long long totalHr = hour(piles,mid);

            if(totalHr <= h){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
};