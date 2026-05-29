class Solution {
public:
    #define ll long long 

    bool check(ll mid , vector<int>& processorTime, vector<int>& tasks) {
        int l = 0;

        ll maxi = 0;
        int cnt = 4;

        for(int i=tasks.size()-1; i>= 0; i--) {
            maxi = max(maxi , (ll)tasks[i] + processorTime[l]);
            cnt--;

            if(cnt == 0) {
                cnt = 4;
                l++;
            }
        }
        return maxi <= mid;
    }

    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int n = processorTime.size();

        sort(processorTime.begin() , processorTime.end());
        sort(tasks.begin() , tasks.end());

        int sz = tasks.size();

        ll low = 1;
        ll high = (processorTime[n-1] + tasks[sz-1]);

        ll ans = LLONG_MAX;

        while(low <= high) {
            ll mid = (low + high) / 2;

            if(check(mid , processorTime , tasks)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};