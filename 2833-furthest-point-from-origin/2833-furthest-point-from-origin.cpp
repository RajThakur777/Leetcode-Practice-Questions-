class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();

        int cnt = 0;
        int l = 0;
        int r = 0;

        for(int i=0; i<n; i++) {
            if(moves[i] == '_') {
                cnt++;
            }
            else if(moves[i] == 'L') {
                l++;
            }
            else {
                r++;
            }
        }
        return abs(l - r) + cnt;
    }
};