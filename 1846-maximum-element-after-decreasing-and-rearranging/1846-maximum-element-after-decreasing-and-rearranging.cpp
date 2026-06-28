class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin() , arr.end());

        int prev = 1;

        for(int i=1; i<n; i++) {
            if(arr[i] == prev) {
                continue;
            }
            else if(arr[i] == prev + 1) {
                prev++;
            }
            else {
                arr[i] = prev + 1;
                prev++;
            }
        }
        return prev;
    }
};