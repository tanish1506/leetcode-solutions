class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = s.size();
        int m = p.size();
        vector<int> freq1(26,0); // for string s
        vector<int> freq2(26,0);// for string p

        if(m>n) return ans;

        for(int i=0;i<m;i++){
            freq2[p[i] - 'a']++;
        }

        for(int i=0;i<n;i++){
            freq1[s[i] - 'a']++;

            if(i >= m){
                freq1[s[i-m] - 'a']--;
            }
            if(freq2 == freq1){
                ans.push_back(i-m+1);
            }
        }
        return ans;
    }
};