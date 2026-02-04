class Solution {
public:
    bool canMake(vector<int>& arr, int mid , int m , int k){
        int b=0,cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] <= mid){
                cnt++;
            }else{
                
                b += (cnt/k);
                cnt=0;
            }
        }
        b += (cnt/k);
        return (b >= m) ? true : false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());

        if((long long)m*k > bloomDay.size()) return -1;

        while(low < high){
            int mid = low+(high-low)/2;
            if(canMake(bloomDay,mid,m,k)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};