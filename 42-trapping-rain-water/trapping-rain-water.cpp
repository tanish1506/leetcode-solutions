class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        vector<int> leftM(n);
        vector<int> rightM(n);
        leftM[0] = height[0];
        rightM[n-1] = height[n-1];

        for(int i=1;i<n;i++){
            leftM[i] = max(leftM[i-1] , height[i]);
        }
        for(int i=n-2;i>=0;i--){
            rightM[i] = max(rightM[i+1],height[i]);
        }

        int wtrtrap = 0;
        for(int i=0;i<n;i++){
            int currwtr = min(leftM[i],rightM[i]) - height[i];
            if(currwtr > 0){
                wtrtrap += currwtr;
            }
        }
        return wtrtrap;

    }
};