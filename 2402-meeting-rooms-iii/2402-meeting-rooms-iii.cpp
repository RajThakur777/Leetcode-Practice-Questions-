class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(meetings.begin() , meetings.end());

        vector<int> roomCnt(n , 0);
        vector<long long> availableRoom(n);

        for(int i=0; i<m; i++) {
            int st = meetings[i][0];
            int ed = meetings[i][1];

            long long miniEnd = LLONG_MAX;
            int r = 0;

            bool f = false;
            for(int room=0; room<n; room++) {
                if(availableRoom[room] <= st) {
                    availableRoom[room] = ed;
                    roomCnt[room]++;
                    f = true;
                    break;
                }

                if(miniEnd > availableRoom[room]) {
                    miniEnd = availableRoom[room];
                    r = room;
                }
            }
            if(!f) {
                roomCnt[r]++;
                availableRoom[r] += (ed - st);
            }
        }

        int maxi = *max_element(roomCnt.begin() , roomCnt.end());
        int idx = -1;
        for(int i=0; i<n; i++) {
            if(maxi == roomCnt[i]) {
                idx = i;
                break;
            }
        }
        return idx;
    }
};