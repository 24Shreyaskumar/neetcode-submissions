class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int i, j, k;
        i = 0;

        while (i < n-2) {
            j = i+1;
            k = n-1;
            int target = -1 * nums[i];

            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j+1 < n && nums[j+1] == nums[j]) j++;
                    j++;
                    while (k-1 >= 0 && nums[k-1] == nums[k]) k--;
                    k--;
                }
                else if (nums[k] + nums[j] < target) {
                    while (j+1 < n && nums[j+1] == nums[j]) j++;
                    j++;
                }
                else {
                    while (k-1 >= 0 && nums[k-1] == nums[k]) k--;
                    k--;
                }
            }

            j = i+1;
            while (j < n && nums[j] == nums[i]) j++;
            i = j;
        }

        if (ans.size())
            return ans;
        return {};
    }
};
