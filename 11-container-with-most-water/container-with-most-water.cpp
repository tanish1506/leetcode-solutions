class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0, j = n-1;
        int ans=0;
        while(i<j){
            int area = 0;
            if(height[i] < height[j]){
                area = height[i] * (j-i);

                ans = max(ans,area);
                i++;
            } else{
                area = height[j] * (j-i);
                ans = max(ans,area);
                j--;
            }

        }
        return ans;

    }
};