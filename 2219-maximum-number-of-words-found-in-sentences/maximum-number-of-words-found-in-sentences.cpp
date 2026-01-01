class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int count=0;

        for(int i=0;i<sentences.size();i++){
            int space = 0;
            int n = sentences[i].size();
            for(int j=0;j<n;j++){
                if(sentences[i][j] == ' '){
                    space++;
                }
            }
            
            count = max(count , space+1);
        }
        return count;
    }
};