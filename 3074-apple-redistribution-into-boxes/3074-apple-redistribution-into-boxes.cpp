class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();

        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += apple[i];
        }

        sort(capacity.rbegin() , capacity.rend());

        int cnt = 0;

        for(int i=0; i<capacity.size(); i++) {
            if(sum <= 0) break;

            sum -= capacity[i];
            cnt++;
        }
        return cnt;
    }
};