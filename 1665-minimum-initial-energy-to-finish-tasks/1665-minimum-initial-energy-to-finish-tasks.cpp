class Solution {
public:

    bool check(int mid , vector<vector<int>>& tasks) {
        int cnt = mid;

        for(int i=0; i<tasks.size(); i++) {
            if(cnt <= 0) {
                return false;
            }

            if(tasks[i][1] > cnt) {
                return false;
            }

            cnt -= tasks[i][0];
        }
        return (cnt >= 0);
    }

    static bool cmp(vector<int> &a , vector<int> &b) {
        return (a[1] - a[0]) > (b[1] - b[0]);
    }

    int minimumEffort(vector<vector<int>>& tasks) {  
        int n = tasks.size(); 

        sort(tasks.begin() , tasks.end() , cmp);

        int low = tasks[0][1];
        int high = 1e9;

        for(int i=0; i<n; i++) {
            cout<<tasks[i][0]<<" "<<tasks[i][1]<<endl;
        }
        cout<<endl;

        int ans = 0;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(check(mid , tasks)) {
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