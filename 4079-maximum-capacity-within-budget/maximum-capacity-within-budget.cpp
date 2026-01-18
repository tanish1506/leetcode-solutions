class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int,int>> machines;
        for(int i = 0; i < n; i++){
            machines.push_back({costs[i], capacity[i]});
        }

        sort(machines.begin(), machines.end());

        vector<int> bestCap(n);
        bestCap[0] = machines[0].second;
        for(int i = 1; i < n; i++){
            bestCap[i] = max(bestCap[i-1], machines[i].second);
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(machines[i].first < budget){
                ans = max(ans, machines[i].second);
            }

            int rem = budget - machines[i].first - 1;
            int l = 0, r = i - 1, idx = -1;

            while(l <= r){
                int mid = (l + r) / 2;
                if(machines[mid].first <= rem){
                    idx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if(idx != -1){
                ans = max(ans, machines[i].second + bestCap[idx]);
            }
        }

        return ans;
    }
};