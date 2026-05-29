class Solution {
public:
    const int mod = 1e9 + 7;

    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();

        sort(arr.begin() , arr.end());

        int ans = 0;

        for(int j=1; j<n-1; j++) {
            int i = 0;
            int k = n-1;

            while(i < j && k > j) {
                int sum = arr[i] + arr[j] + arr[k];

                if(sum > target) {
                    k--;
                }
                else if(sum < target) {
                    i++;
                }
                else {
                    int i1 = i;
                    int k1 = k;

                    while(i1 < j && arr[i1] == arr[i]) {
                        i1++;
                    }

                    while(k1 > j && arr[k1] == arr[k]) {
                        k1--;
                    }

                    ans = ((ans % mod + ((i1 - i) * (k - k1)) % mod)) % mod;

                    i = i1;
                    k = k1;
                }
            }
        }
        return ans;
    }
};