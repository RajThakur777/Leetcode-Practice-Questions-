class Solution {
public:

    bool check(int mid , vector<int> &d , int k) {
        int cnt = k-1;
        int val = d[0] + mid;

        int n = d.size();

        for(int i=1; i<d.size(); i++) {
            if(cnt == 0) {
                return true;
            }

            int idx = lower_bound(d.begin() , d.end() , val) - d.begin();

            if(idx == n) {
                if(cnt == 0) {
                    return true;
                }
                else {
                    return false;
                }
            }

            cnt--;
            val = d[idx];
            val += mid;
        }
        return (cnt == 0);
    }

    int maximumTastiness(vector<int>& price, int k) {
       int n = price.size(); 

        set<int> st;

        for(int i=0; i<n; i++) {
           st.insert(price[i]);
        }

        vector<int> d;
        for(auto it : st) {
            d.push_back(it);
        }

        int low = 0;
        int high = 1e9;

        int ans = 0;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(check(mid , d , k)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};