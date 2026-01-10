class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0,r=n-1,leftM=0,rightM=0,water=0;
        while(l<r){
            if(height[l] <= height[r]){
                if(height[l] >= leftM){
                    leftM = height[l];
                }else{
                    water += leftM - height[l];
                }
                l++;
            }
            else{
                if(height[r] >= rightM){
                    rightM = height[r];
                }
                else{
                    water += rightM - height[r];
                }
                r--;
            }
        }
        return water;
    }
};