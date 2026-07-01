class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxA=0;
        int nse,pse,ele;
        int n = heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                ele = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxA = max( maxA , heights[ele] * (nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            nse = n;
            ele = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            maxA = max(maxA , heights[ele] * (nse-pse-1));
        }
        return maxA;
    }
};