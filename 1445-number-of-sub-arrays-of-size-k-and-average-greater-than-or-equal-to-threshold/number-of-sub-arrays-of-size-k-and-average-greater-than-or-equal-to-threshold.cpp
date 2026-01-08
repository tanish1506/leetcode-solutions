class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int r=0,l=0,sum=0,cnt=0;
        int n=arr.size();
        while(r<n){
            sum += arr[r];
            if((r-l+1) > k){
                sum -= arr[l];
                l++;
            }
            if((r-l+1) == k){
                if(sum >= k*threshold){
                    cnt++;
                }
            }
            r++;
        }
        return cnt;
    }
};