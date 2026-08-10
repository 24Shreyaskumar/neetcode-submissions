class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        
        for (int i = 0; i < n-2; i++) {
            unordered_set<int> seen;
            int target = -1 * nums[i];
            vector<int> res = {};
            for (int j = i+1; j < n; j++) {
                if (seen.find(target - nums[j]) != seen.end()) {
                    res = {-1 * target, *seen.find(target - nums[j]), nums[j]};
                    sort(res.begin(), res.end());
                    st.insert(res);
                }
                seen.insert(nums[j]);
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
