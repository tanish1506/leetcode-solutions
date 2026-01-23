class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m>n) return "";

        unordered_map<char,int> needmap;
        for(char c : t){
            needmap[c]++;
        }

        unordered_map<char,int> window;
        int l=0,start=0,minlen = INT_MAX;

        int need = needmap.size();
        int have = 0;

        for(int r=0;r<n;r++){
            char c = s[r];
            window[c]++;

            if(needmap.count(c) && window[c] == needmap[c]){
                have++;
            }
            while(need == have){
                if((r-l+1) < minlen){
                    minlen = r-l+1;
                    start = l;
                }
                window[s[l]]--;
                if(needmap.count(c) && window[s[l]] < needmap[s[l]]){
                    have--;
                }
                l++;
            }
        }

        return minlen == INT_MAX ? "" : s.substr(start,minlen);
    }
};