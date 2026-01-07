class Solution {
public:
    int characterReplacement(string s, int k) {
        int r=0,l=0,maxlen=0,maxf=0;
        int n = s.size();
        int hash[26] = {0};
        while(r<n){
            hash[s[r] - 'A']++;
            maxf = max(maxf , hash[s[r] - 'A']);

            if((r-l+1) - maxf > k){
                hash[s[l] -'A']--; maxf = 0;
                // for(int i=0;i<26;i++) maxf = max(maxf,hash[i]);
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};