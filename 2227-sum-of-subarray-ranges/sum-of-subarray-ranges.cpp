class Solution {
public:
    vector<int> nextSmall(vector<int> nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmall(vector<int> nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return ans;
    }
    vector<int> nextGreat(vector<int> nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return ans;
    }
    vector<int> prevGreat(vector<int> nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> nse = nextSmall(nums);
        vector<int> pse = prevSmall(nums);

        vector<int> nge = nextGreat(nums);
        vector<int> pge = prevGreat(nums);

        long long miniSum=0;
        long long maxiSum=0;

        for(int i=0;i<n;i++){
            long long left = i - pge[i];
            long long rgt = nge[i] - i;

            maxiSum += 1LL * left * rgt * nums[i];
        }
        for(int i=0;i<n;i++){
            long long left = i - nse[i];
            long long rgt = pse[i] - i;

            miniSum += 1LL * left * rgt * nums[i];
        }
        return maxiSum - miniSum;
    }
};