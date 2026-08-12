class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), res = 0, mx = 0;
        unordered_map<int, int> mp;

        for (int i = 0, j = 0; j < n; j++) {
            mp[s[j]]++;
            mx = max(mx, mp[s[j]]);
            if (j-i+1 - mx <= k) {
                res = max(res, j-i+1);
                continue;
            }

            while (j-i+1 - mx > k) {
                mp[s[i++]]--;
            }
        }

        return res;
    }
};
