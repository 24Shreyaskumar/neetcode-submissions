class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> a1(26, 0), a2(26, 0);

        for (auto i : s1)
            a1[i-'a']++;

        for (int i = 0, j = 0; j < m; j++) {
            a2[s2[j] - 'a']++;
            if (j-i+1 < n) continue;
            if (a1 == a2) return true;
            a2[s2[i++]-'a']--; 
        }

        return false;
    }
};
