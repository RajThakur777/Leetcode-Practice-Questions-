class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();

        vector<int> time(n);
        for(int i=0; i<n; i++) {
            time[i] = ceil((1.0 * dist[i]) / speed[i]);
        }

        sort(time.begin() , time.end());

        int t = 1;

        for(int i=0; i<n; i++) {
            if(t > time[i]) {
                return i;
            }
            t++;
        }
        return n;
    }
};