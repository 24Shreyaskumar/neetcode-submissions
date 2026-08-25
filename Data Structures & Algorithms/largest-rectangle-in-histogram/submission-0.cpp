class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> st;
        int mxa = 0;

        for (int i = 0; i < n; i++) {
            int curi = i;
            while (st.size() && st.top().second > heights[i]) {
                mxa = max(mxa, st.top().second * (i - st.top().first));
                curi = st.top().first;
                st.pop();
            }

            st.push({curi, heights[i]});
        }

        while (st.size()) {
            cout<<st.top().first<<" "<<st.top().second<<"\n";
            mxa = max(mxa, st.top().second * (n - st.top().first));
            st.pop();
        }

        return mxa;
    }
};
