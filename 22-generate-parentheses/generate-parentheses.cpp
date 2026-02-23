class Solution {
public:
    void check(int open,int close, string curr, vector<string> &ans,int n){
        if(open == n && close == n){
            ans.push_back(curr);
            return ;
        }
        if(open < n){
            check(open+1,close,curr+"(",ans,n);
        }
        if(close < open){
            check(open,close+1,curr+")",ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        check(0,0,"",ans,n);
        return ans;
    }
};