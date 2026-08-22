class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> time(n);

        for (int i = 0; i < n; i++)
            time[i] = {position[i], speed[i]};

        sort(time.begin(), time.end(), greater<pair<int, int>>());

        stack<double> st;

        for (int i = 0; i < n; i++) {
            double t = (double) ((target - time[i].first) / (double) time[i].second);
            if (st.size() && i < n && st.top() >= t)
                continue;
            st.push(t);
        }

        return st.size();
    }
};

