class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();

        map<int , set<int>> mpp;

        for(int i=0; i<m; i++) {
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];

            mpp[row].insert(seat);
        }

        int total = (n * 2);

        for(auto it : mpp) {
            set<int> st = it.second;

            bool left = true;
            bool right = true;
            bool middle = true;

            for(int i=2; i<=5; i++) {
                if(st.find(i) != st.end()) {
                    left = false;
                    break;
                }
            }

            for(int i=4; i<=7; i++) {
                if(st.find(i) != st.end()) {
                    middle = false;
                    break;
                }
            }

            for(int i=6; i<=9; i++) {
                if(st.find(i) != st.end()) {
                    right = false;
                    break;
                }
            }

            if(left && right) {

            }
            else if(left || middle || right) {
                total--;
            }
            else {
                total -= 2;
            }
        }
        return total;
    }
};