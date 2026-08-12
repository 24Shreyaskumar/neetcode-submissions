class Solution {
public:
    string minWindow(string s, string t) {
        if (s == t) return t;
        int n = s.size(), m = t.size();
        int count = 0, res = n;
        int i, j, it = 0, jt = -1;
        unordered_map<int, int> a1, a2;
        unordered_set<int> seen;

        for (auto i : t) {
            a1[i]++;
        }

        for (i = 0, j = 0; j < n; j++) {
            if (a1.count(s[j])) {
                a2[s[j]]++;
                if (a2[s[j]] >= a1[s[j]] && seen.find(s[j]) == seen.end()) {
                    count += a1[s[j]];
                    seen.insert(s[j]);
                }
            }

            while (count == m) {
                if (res >= j-i+1) {
                    it = i, jt = j;
                    res = j-i+1;
                }
                a2[s[i]]--;
                if (a2[s[i]] < a1[s[i]] && seen.find(s[i]) != seen.end()) {
                    count -= a1[s[i]];
                    seen.erase(s[i]);
                }
                i++;
            }
        }

        string ans = s.substr(it, jt - it + 1);
        return ans;
    }
};
