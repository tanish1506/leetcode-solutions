class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count[101] = {0};
        for(int i=0;i<heights.size();i++){
            count[heights[i]]++;
        }
        int idx = 0,result=0;
        for(int h=1;h<101;h++){
            while(count[h] > 0){
                if(heights[idx] != h){
                    result++;
                }
                idx++;
                count[h]--;
            }
        }
        return result;
    }
};