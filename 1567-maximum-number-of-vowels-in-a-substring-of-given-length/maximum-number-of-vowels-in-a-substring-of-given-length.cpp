class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int r=0,l=0,len=0,maxlen = 0;
        while(r<n){
            if(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u'){
                len++;
            }
            if((r-l+1) > k){
                if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u'){
                    len--;
                }
                l++;
            }
            maxlen = max(maxlen,len);
            r++;
        }
        return maxlen;
    }
};