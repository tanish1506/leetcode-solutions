class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int cnt=0;
        unordered_map<char,int> f;
        for(int i=0;i<n;i++){
            f[s[i]]++;
            if(i >= 3){
                f[s[i-3]]--;
                if(f[s[i-3]] == 0){
                    f.erase(s[i-3]);
                }
            }
            if(f.size() == 3){
                cnt++;
            }
        }
        return cnt;
    }
};