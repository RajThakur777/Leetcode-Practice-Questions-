class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();

        sort(maximumHeight.rbegin() , maximumHeight.rend());

        vector<int> arr;

        arr.push_back(maximumHeight[0]);

        for(int i=1; i<n; i++) {
            int val = min({arr.back() - 1 , maximumHeight[i]});
            arr.push_back(val);
        }

        long long ans = 0;

        for(int i=0; i<arr.size(); i++) {
            if(arr[i] <= 0) {
                return -1;
            }
            else {
                ans += arr[i];
            }
        }
        return ans;
    }
};