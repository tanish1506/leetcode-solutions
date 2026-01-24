class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int n = items.size();
        int idx,count=0;
        if(ruleKey == "type") idx=0;
        else if (ruleKey == "color") idx = 1;
        else idx = 2;

        for(int i=0;i<n;i++){
            if(items[i][idx] == ruleValue){
                count++;
            }
        }
        return count;
    }
};