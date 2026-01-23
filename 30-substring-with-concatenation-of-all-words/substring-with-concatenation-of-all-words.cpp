class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(words.empty()) return ans;

        int wordlen = words[0].size();
        int k = words.size();
        int totallen = wordlen*k;

        unordered_map<string, int> need;
        for(string c : words) need[c]++;

        for(int offset = 0;offset< wordlen;offset++){
            unordered_map<string,int> window;
            int left=offset;
            int count = 0;

            for(int r = offset ; r + wordlen <= s.size() ; r+=wordlen){
                string word = s.substr(r,wordlen);

                if(need.count(word)){
                    window[word]++;
                    count++;

                    while(window[word] > need[word]){
                        string leftword = s.substr(left,wordlen);
                        window[leftword]--;
                        left += wordlen;
                        count--;
                    }
                    if(count == k){
                        ans.push_back(left);
                    }
                }
                else{
                    window.clear();
                    count=0;
                    left= r + wordlen;
                }
            }
        }
        return ans;
    }
};