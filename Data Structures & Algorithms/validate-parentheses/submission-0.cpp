class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        unordered_map<char, char> mp = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (auto i : s) {
            if (i == '(' || 
                i == '{' ||
                i == '[')
                open.push(i);
            else {
                if (!open.size() || open.top() != mp[i])
                    return false;
                open.pop();
            }
        }

        return open.empty();
    }
};
