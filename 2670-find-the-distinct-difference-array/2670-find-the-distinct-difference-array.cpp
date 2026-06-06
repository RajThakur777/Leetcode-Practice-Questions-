class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n);
        vector<int> suffix(n);

        set<int> s1;
        set<int> s2;

        prefix[0] = 1;
        s1.insert(nums[0]);

        suffix[n-1] = 1;
        s2.insert(nums[n-1]);

        for(int i=1; i<n; i++) {
            if(s1.find(nums[i]) == s1.end()) {
                prefix[i] = prefix[i-1] + 1;
                s1.insert(nums[i]);
            }
            else {
                prefix[i] = prefix[i-1];
            }
        }

        for(int i=n-2; i>=0; i--) {
            if(s2.find(nums[i]) == s2.end()) {
                suffix[i] = suffix[i+1] + 1;
                s2.insert(nums[i]);
            }
            else {
                suffix[i] = suffix[i+1];
            }
        }

        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            cout<<prefix[i]<<" "<<suffix[i]<<endl;
        }

        for(int i=0; i<n; i++) {
            if(i == n-1) {
                ans[i] = (prefix[n-1]);
            }
            else {
                ans[i] = prefix[i] - suffix[i+1];
            }
        }
        return ans;
    }
};