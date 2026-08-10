class Solution {
public:
    bool isPalindrome(string s) {
        unordered_set<char> an;

        for (int i = 0; i < 26; i++)
            an.insert('a'+i);
        for (int i = 0; i < 9; i++) {
            an.insert(i+'0');
        }

        int i = 0, j = s.size()-1;

        while (i < j) {
            while (i < j && an.find(tolower(s[i])) == an.end()) i++;
            while (i < j && an.find(tolower(s[j])) == an.end()) j--;

            if (tolower(s[i]) != tolower(s[j]))
                return false;
            i++, j--;
        }

        return true;
    }
};
