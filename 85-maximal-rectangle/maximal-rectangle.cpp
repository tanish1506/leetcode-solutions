class Solution {
public:
    int lhist(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        int maxi=0;
        int nse,pse,element;
    
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || arr[st.top()] >= arr[i])){
                element = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                
                maxi = max(maxi, arr[element] * (nse-pse-1));
            }
            st.push(i);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        int area=0;

        vector<vector<int>> psum(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum++;
                if(matrix[i][j] == '0') sum=0;
                psum[i][j] = sum;
            }
        }
        for(int i=0;i<n;i++){
            area = max(area,lhist(psum[i]));
        }
        return area;
    }
};