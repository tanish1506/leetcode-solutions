class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, curr=1,prev=0;
        for(int i=1;i<s.size();i++){
            if(s[i] == s[i-1]){
                curr++;
            }else{
                ans += min(curr,prev);
                prev = curr;
                curr = 1;
            }
        }
        ans += min(curr,prev);
        return ans;
    }
};