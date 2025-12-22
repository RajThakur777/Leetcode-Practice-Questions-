class Solution {
public:
    int minimumCardPickup(vector<int>& cards) { 
        int n = cards.size();

        int ans = INT_MAX;

        int i = 0;
        unordered_map<int , int> mpp;
        for(int j=0; j<n; j++) {
            mpp[cards[j]]++;

            while(mpp[cards[j]] > 1) {
                ans = min(ans , (j - i + 1));
                mpp[cards[i]]--;
                if(mpp[cards[i]] == 0) {
                    mpp.erase(cards[i]);
                }
                i++;
            }
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};