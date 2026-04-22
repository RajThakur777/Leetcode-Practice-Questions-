class Solution {
public:
  
    bool check(int mid , vector<int> &grades) {
        int group = 1;
        int cnt = 0;
        int prev_sum = grades[0];
        int sum = 0;

        for(int i=1; i<grades.size(); i++) {
            sum += grades[i];
            cnt++;

            if(sum > prev_sum && cnt > group) {
                group++;
                cnt = 0;
                prev_sum = sum;
                sum = 0;
            }
        }
        return (group >= mid);
    }

    int maximumGroups(vector<int>& grades) {
        int n = grades.size();

        sort(grades.begin() , grades.end());

        int ans = 0;

        int low = 1;
        int high = n;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(check(mid , grades)) {
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