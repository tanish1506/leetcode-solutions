class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int n = height.size();
        int i = 0;
        int j = n-1;
        int max = 0;
        while(i < j){
            if(height[i] < height[j]){
                area = height[i] * (j-i);
                i++;
                if(max < area){
                    max = area;
                }
            }
            else{
                area = height[j] * (j-i);
                j--;
                if(max < area){
                    max = area;
                }
            }
        }
        return max;
    }
};