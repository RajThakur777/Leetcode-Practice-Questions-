class Solution {
public:

    bool isArithmetic(vector<int> &arr) {
        if(arr.size() <= 1) {
            return false;
        }

        int d = arr[1] - arr[0];

        for(int i=2; i<arr.size(); i++) {
            if((arr[i] - arr[i-1]) != d) {
                return false;
            } 
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();

        int m = l.size();

        vector<bool> ans(m);

        for(int i=0; i<m; i++) {
            int l1 = l[i];
            int r1 = r[i];

            vector<int> arr;

            for(int i=l1; i<=r1; i++) {
                arr.push_back(nums[i]);
            }

            sort(arr.begin() , arr.end());

            for(auto x : arr) {
                cout<<x<<" ";
            }
            cout<<endl;

            if(isArithmetic(arr)) {
                ans[i] = true;
            }
            else {
                ans[i] = false;
            }
        }
        return ans;
    }
};