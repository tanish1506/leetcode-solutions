class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        vector<int> up(m + 1, 0);
        vector<int> down(m + 1, 0);

        
        // for(int a = 1; a <= m; a++) {
        //     for(int b = 1; b <= m; b++) {

        //         if(a == b) continue;

        //         if(a < b)
        //             up[b]++;
        //         else
        //             down[b]++;
        //     }
        // }
        for(int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        
        vector<int> newUp(m + 1, 0);
        vector<int> newDown(m + 1, 0);

        vector<int> prefUp(m + 1, 0);
        vector<int> prefDown(m + 1, 0);

        for(int len = 3; len <= n; len++) {

            fill(newUp.begin(), newUp.end(), 0);
            fill(newDown.begin(), newDown.end(), 0);

            prefUp[0] = 0;
            prefDown[0] = 0;

            for(int v = 1; v <= m; v++) {

                prefUp[v] =
                    (prefUp[v-1] + up[v]) % MOD;

                prefDown[v] =
                    (prefDown[v-1] + down[v]) % MOD;
            }

            for(int v = 1; v <= m; v++) {

                newUp[v] = prefDown[v-1];

                newDown[v] =
                    (prefUp[m] - prefUp[v] + MOD) % MOD;
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;

        if(n == 2) {
            for(int v = 1; v <= m; v++) {
                ans = (ans + up[v]) % MOD;
                ans = (ans + down[v]) % MOD;
            }
            return (int)ans;
        }

        for(int v = 1; v <= m; v++) {
            ans = (ans + up[v]) % MOD;
            ans = (ans + down[v]) % MOD;
        }

        return (int)ans;
    }
};