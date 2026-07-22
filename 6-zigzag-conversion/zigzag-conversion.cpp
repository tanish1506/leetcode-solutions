class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)return s;
        int currRow=0;
        vector<string> rows(numRows);
        bool rowDown = false;

        for(char ch : s){
            rows[currRow] += ch;

            if(currRow == 0 || currRow == numRows-1){
                rowDown = !rowDown;
            }
            if(rowDown){
                currRow++;
            }else{
                currRow--;
            }
        }
        string ans = "";
        for(string st : rows){
            ans += st;
        }
        return ans;
    }
};