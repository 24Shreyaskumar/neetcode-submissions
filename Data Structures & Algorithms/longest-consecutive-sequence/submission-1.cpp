class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int lcs = 0;
        unordered_set<int> st;

        for (auto i : nums)
            st.insert(i);

        for (auto i : st) {
            if (st.find(i-1) != st.end()) continue;
            int seq = i+1;
            while (st.find(seq) != st.end()) seq++;
            lcs = max(lcs, seq - i);
        }

        return lcs;
    }
};
