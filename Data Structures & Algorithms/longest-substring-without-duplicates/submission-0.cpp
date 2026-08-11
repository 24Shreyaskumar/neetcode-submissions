class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0;
        unordered_map<int, int> mp;

        for (int i = 0, j = 0; j < n; j++) {
            mp[s[j]]++;
            if (mp.size() == j-i+1) {
                res = max(res, j-i+1);
                continue;
            }

            while (mp.size() < j-i+1) {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
        }

        return res;
    }
};
