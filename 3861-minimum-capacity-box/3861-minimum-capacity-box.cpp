class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();

        int ans = INT_MAX;

        for(int i=0; i<n; i++) {
            if(capacity[i] >= itemSize) {
                ans = min(ans , capacity[i]);
            }
        }

        for(int i=0; i<n; i++) {
            if(capacity[i] == ans) {
                return i;
            }
        }
        return -1;
    }
};