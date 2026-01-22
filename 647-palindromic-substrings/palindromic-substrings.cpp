class Solution {
public:
    void expand(string &s, int left, int right , int &count){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            count++;
            left--;
            right++;
        }

    }
    int countSubstrings(string s) {
        int n = s.size();
        int count=0;
        for(int i =0;i<n;i++){
            expand(s,i,i,count); // odd
            expand(s,i,i+1,count); //even
        }
        return count;
    }

};