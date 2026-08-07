class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if (t.size() != n) return false;

        vector<int> mp1(26, 0), mp2(26, 0);
        
        for (int i = 0; i < n; i++)
            mp1[s[i]-'a']++, mp2[t[i]-'a']++;

        return mp1 == mp2;
    }
};
