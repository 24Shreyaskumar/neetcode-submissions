class Solution {
public:
    bool possible(int k, vector<int>& piles, int h) {
        int hours = 0;
        for (auto i : piles) {
            hours += ceil((double) i / (double) k);
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = 0;
        for (auto i : piles)
            mx = max(mx, i);

        int low = 1, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (possible(mid, piles, h))
                high = mid;
            else
                low = mid+1;
        }

        return low;
    }
};
