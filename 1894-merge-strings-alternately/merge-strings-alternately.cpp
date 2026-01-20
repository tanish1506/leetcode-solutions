class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0,k=0;
        int n = word1.size();
        int m = word2.size();
        string res;
        res.resize(n+m);
        while(i < n && j < m){
            if(k%2 == 0){
                res[k++] = word1[i++];
            }
            else{
                res[k++] = word2[j++];
            }
        }
        while(i<n){
            res[k++] = word1[i++];
        }
        while(j<m){
            res[k++] = word2[j++];
        }

        return res;
    }
};