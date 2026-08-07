class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<vector<int>, vector<string>> mp;
        vector<vector<string>> res;

        for (auto str : strs) {
            vector<int> freq(26, 0);
            for (auto s : str)
                freq[s-'a']++;
            mp[freq].push_back(str);
        }

        for (auto i : mp) {
            res.push_back(i.second);
        }

        return res;
    }
};
