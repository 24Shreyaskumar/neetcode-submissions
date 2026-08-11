class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), res = 0;
        vector<int> mn(n), mx(n);
        mn[0] = prices[0];
        mx[n-1] = prices[n-1];
        
        for (int i = 1; i < n; i++) {
            mn[i] = min(prices[i], mn[i-1]);
            mx[n-i-1] = max(prices[n-i-1], mx[n-i]);
        }

        for (int i = 0; i < n; i++) {
            res = max(res, mx[i]-mn[i]);
        }

        return res;
    }
};
