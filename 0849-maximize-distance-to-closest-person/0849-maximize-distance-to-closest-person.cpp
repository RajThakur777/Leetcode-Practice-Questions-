class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();

        vector<int> prefix(n , -1);
        vector<int> suffix(n , -1);

        int idx1 = -1;
        if(seats[0] == 1) {
            idx1 = 0;
        }

        for(int i=1; i<n; i++) {
            if(seats[i] == 1) {
                idx1 = i;
            }
            else {
                prefix[i] = idx1;
            }
        }

        int idx2 = -1;
        if(seats[n-1] == 1) {
            idx2 = n-1;
        }

        for(int i=n-2; i>=0; i--) {
            if(seats[i] == 1) {
                idx2 = i;
            }
            else {
                suffix[i] = idx2;
            }
        }

        int ans = 0;

        for(int i=0; i<n; i++) {
            if(seats[i] == 0) {
                int left = prefix[i];
                int right = suffix[i];

                int res = INT_MAX;

                if(left != -1) {
                    res = min(res , abs(i - left));
                }

                if(right != -1) {
                    res = min(res , abs(right - i));
                }

                ans = max(ans , res);
            }
        }

        if(seats[0] == 0) {
            for(int i=1; i<n; i++) {
                if(seats[i] == 1) {
                    ans = max(ans , abs(i));
                    break;
                }
            }
        }

        if(seats[n-1] == 0) {
            for(int i=n-2; i>=0; i--) {
                if(seats[i] == 1) {
                    ans = max(ans , abs(n-1-i));
                    break;
                }
            }
        }
        
        return ans;
    }
};