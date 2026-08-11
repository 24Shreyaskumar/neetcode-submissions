class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int mxa = 0;
        int i = 0, j = n-1;

        while (i < j) {
            mxa = max(mxa, (min(heights[i], heights[j]) * (j-i)));
            if (heights[i] <= heights[j]) i++;
            else j--;
        }

        return mxa;
    }
};
