class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;

        while(n > 0) {
            arr.push_back(n % 10);
            n /= 10;
        }

        sort(arr.begin() , arr.end());

        int sz = arr.size();

        return arr[sz-1] * arr[sz-2];
    }
};