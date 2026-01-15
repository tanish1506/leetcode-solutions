class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int> freq;
        for(char c : s){
            freq[c]++;
        }

        vector<vector<char>> bucket(n+1);
        for(auto &p : freq){
            bucket[p.second].push_back(p.first);
        }

        string res;
        for(int i=n;i>=1;i--){
            for( char c : bucket[i]){
                res.append(i,c);
            }
        }
        return res;
    }
};