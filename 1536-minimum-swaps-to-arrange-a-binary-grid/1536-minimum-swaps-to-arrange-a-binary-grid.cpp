class Solution {
public:

    int bubble_sort(vector<int> &arr , int n) {
        int ops = 0;

        int value = n - 1;

        for(int i=0; i<n; i++) {
            if(arr[i] >= value) {
                value--;
                continue;
            }

            bool f = false;
            int idx = -1;
            for(int j=i+1; j<n; j++) {
                if(arr[j] >= value) {
                    f = true;
                    idx = j;
                    break;
                }
            }

            if(!f) {
                return -1;
            }
            else {
                for(int k=idx; k>i; k--) {
                    swap(arr[k] , arr[k-1]);
                    ops++;
                }
                value--;
            }
        }
        return ops;
    }

    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> arr;

        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=n-1; j>=0; j--) {
                if(grid[i][j] == 1) {
                    break;
                }
                else {
                    cnt++;
                }
            }
            arr.push_back(cnt);
        }

        int ans = bubble_sort(arr , n);

        return ans;
    }
};