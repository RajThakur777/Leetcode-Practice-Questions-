class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int p = 0;

        int ans = 0;

        for(int i=0; i<requests.size(); i++) {
            ans += abs(p - requests[i]);
            p = requests[i];
        }

        return ans;
    }
};