class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int freq[101] = {0};
        for(int i=0;i<heights.size();i++){
            freq[heights[i]]++;
        }
        int idx = 0, count=0;
        for(int i=1;i<=100;i++){
            while(freq[i] > 0){
                if(heights[idx] != i){
                    count++;
                }
                idx++;
                freq[i]--;
            }
        }
        return count;
    }
};