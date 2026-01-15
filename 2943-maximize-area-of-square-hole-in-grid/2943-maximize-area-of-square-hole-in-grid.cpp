class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int hs = hBars.size();
        int vs = vBars.size();

        sort(hBars.begin() , hBars.end());
        sort(vBars.begin() , vBars.end());

        int lh = 1;
        int prev_h = hBars[0];
        int cnt_h = 0;

        for(int i=1; i<hs; i++) {
            if((hBars[i] - prev_h) == 1) {
                lh++;
            }
            else {
                cnt_h = max(cnt_h , lh);
                lh = 1;
            }
            prev_h = hBars[i];
        }
        cnt_h = max(cnt_h , lh);



        int lv = 1;
        int prev_v = vBars[0];
        int cnt_v = 0;

        for(int i=1; i<vs; i++) {
            if((vBars[i] - prev_v) == 1) {
                lv++;
            }
            else {
                cnt_v = max(cnt_v , lv);
                lv = 1;
            }
            prev_v = vBars[i];
        }

        cnt_v = max(cnt_v , lv);

        int value = min(cnt_h , cnt_v);

        int side = value + 1;

        return side * side;
    }
};