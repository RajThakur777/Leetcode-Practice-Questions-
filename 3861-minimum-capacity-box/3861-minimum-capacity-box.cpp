class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();

        int ans = INT_MAX;
        int idx = -1;

        for(int i=0; i<n; i++) {
            if(capacity[i] >= itemSize && capacity[i] < ans) {
                ans = min(ans , capacity[i]);
                idx = i;
            }
        }
        return idx;
    }
};