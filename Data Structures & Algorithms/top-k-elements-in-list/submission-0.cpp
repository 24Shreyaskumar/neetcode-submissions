class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<vector<int>> pq;
        vector<int> res;

        for (auto i : nums)
            mp[i]++;

        for (auto i : mp) {
            pq.push({-1 * i.second, i.first});
            if (pq.size() > k) pq.pop();
        }

        while (pq.size()) {
            res.push_back(pq.top()[1]);
            pq.pop();
        }

        return res;
    }
};
