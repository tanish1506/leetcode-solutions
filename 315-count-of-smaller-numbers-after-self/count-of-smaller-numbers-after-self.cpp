class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> index(n);
        vector<int> count(n,0);

        for(int i=0;i<n;i++){
            index[i] = i;
        }
        mergesort(nums,index,count,0,n-1);
        return count;
    }
    void mergesort(vector<int>& nums,vector<int>& index,vector<int>& count,int left , int right){
        if(left>=right) return;
        int mid = left + (right-left)/2;
        mergesort(nums,index,count,left,mid);
        mergesort(nums,index,count,mid+1,right);

        merge(nums,index,count,left,mid,right);
    }
    void merge(vector<int>& nums,vector<int>& index,vector<int>& count,int left,int mid , int right){
        vector<int> temp(right-left+1);
        int i=left,j=mid+1,k=0;
        int rightSmaller=0;

        while(i <= mid && j <= right){
            if(nums[index[i]] > nums[index[j]]){
                temp[k++] = index[j++];
                rightSmaller++;
            }else{
                count[index[i]] += rightSmaller;
                temp[k++] = index[i++];
            }
        }
        while(i <= mid){
            count[index[i]] += rightSmaller;
            temp[k++] = index[i++];
        }
        while(j <= right){
            temp[k++] = index[j++];
        }

        for(int i=0;i<temp.size();i++){
            index[left + i] = temp[i];
        }
    }
};