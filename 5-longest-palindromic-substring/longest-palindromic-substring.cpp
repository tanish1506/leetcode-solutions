class Solution {
public:
    void check(string &s, int l, int r, int &start, int &maxlen){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            if(r-l+1 > maxlen){
                start = l;
                maxlen = r-l+1;
            }
            r++;
            l--;
        }
    }
    string longestPalindrome(string s) {
        int n =s.size();
        int start=0,maxlen=1;
        for(int i=0;i<n;i++){
            check(s,i,i,start,maxlen); //odd
            check(s,i,i+1,start,maxlen);//even
        }
        return s.substr(start,maxlen);
    }

};