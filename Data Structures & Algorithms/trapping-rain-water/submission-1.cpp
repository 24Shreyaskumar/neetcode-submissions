class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int trapped = 0;
        vector<int> l(n), r(n);

        l[0] = height[0];
        r[n-1] = height[n-1];

        for (int i = 1; i < n; i++) {
            l[i] = max(height[i], l[i-1]);
            r[n-i-1] = max(height[n-i-1], r[n-i]);
        }

        for (int i = 1; i < n-1; i++) {
            trapped += (min(l[i], r[i]) - height[i]);
        }

        return trapped;
    }
};
