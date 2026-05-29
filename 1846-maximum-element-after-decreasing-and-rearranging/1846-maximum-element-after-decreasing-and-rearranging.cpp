class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin() , arr.end());

        int prev = arr[0];

        if(prev != 1) {
            prev = 1;
            arr[0] = 1;
        } 

        for(int i=1; i<n; i++) {
            if(arr[i] - prev <= 1) {
                prev = arr[i];
            }
            else {
                int val = prev + 1;
                prev = val;
                arr[i] = val;
            }
        }

        return *max_element(arr.begin() , arr.end());
    }
};