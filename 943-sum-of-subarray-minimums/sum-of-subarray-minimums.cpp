class Solution {
public:
    vector<int> findNse(vector<int> & arr){
        stack<int> st;
        vector<int> nse(arr.size());
        int n = arr.size();
        for(int i = arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return nse;
    }
    vector<int> findPse(vector<int> & arr){
        vector<int> pse(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);
        int n = arr.size();
        long long total = 0;
        const int MOD = 1e9 + 7;
        for(int i=0;i<n;i++){
            int left = i - pse[i];
            int rgt = nse[i] - i;

            total = (total + (rgt * left * 1LL * arr[i]) % MOD) % MOD;
        }
        return total;
    }
};