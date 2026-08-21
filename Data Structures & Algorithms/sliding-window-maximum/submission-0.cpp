class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 5 4 3 2 1
        // [5 4 3] 2 1 -> 5
        // 5 [4 3 2] 1 -> 4
        // 5 4 [3 2 1] -> 3
        
        int n = nums.size();
        priority_queue<int> pq;
        unordered_map<int, int> mp;
        vector<int> res;

        for (int i = 0, j = 0; j < n; j++) {
            mp[nums[j]]++;
            pq.push(nums[j]);
            if (j-i+1 < k) continue;

            else {
                while (!mp.count(pq.top()))
                    pq.pop();
                res.push_back(pq.top());
                mp[nums[i]]--;
                if (!mp[nums[i]])
                    mp.erase(nums[i]);
                i++;
            }
        }

        return res;
    }
};
