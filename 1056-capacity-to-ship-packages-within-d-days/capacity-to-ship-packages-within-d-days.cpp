class Solution {
public:
    int maxi(vector<int>& weights){
        int maxx = INT_MIN;
        for(int i=0;i<weights.size();i++){
            maxx = max(maxx,weights[i]);
        }
        return maxx;
    }
    int maxSum(vector<int>& weights){
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
        }
        return sum;
    }
    int dayNum(vector<int>& weights, int capacity){
        int day=1,load=0;
        for(int i=0;i<weights.size();i++){
            if(load + weights[i] > capacity){
                day += 1;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = maxi(weights),right = maxSum(weights);

        while(left<=right){
            int mid = left+(right-left)/2;
            int day = dayNum(weights,mid);
            if(day <= days){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
};