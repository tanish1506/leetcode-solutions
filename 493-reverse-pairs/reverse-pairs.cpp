class Solution {
public:
int cnt = 0;
    void merge(vector<int> &nums, int low, int mid, int high){
        int i=low,j=mid+1;
        vector<int> temp;
        while(i <= mid && j <= high){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i++]);
            }
            else{
                temp.push_back(nums[j++]);
            }
        }
        while(i <= mid){
            temp.push_back(nums[i++]);
        }
        while(j <= high){
            temp.push_back(nums[j++]);
        }
        for(int i=0;i<temp.size();i++){
            nums[i+low] = temp[i];
        }
    }
    void count(vector<int> &nums,int low,int mid, int high){
        int right = mid+1;
        for(int i=low;i<=mid;i++){
            while(right <= high && (long long)nums[i] > 2LL * nums[right]) right++;
            cnt += (right - (mid+1));
        }
    }
    void mergesort(vector<int> &nums,int low,int high){
        if(low >= high) return;

        int mid = low+(high-low)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        count(nums,low,mid,high);
        merge(nums,low,mid,high);
    }
    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return cnt;
    }
};