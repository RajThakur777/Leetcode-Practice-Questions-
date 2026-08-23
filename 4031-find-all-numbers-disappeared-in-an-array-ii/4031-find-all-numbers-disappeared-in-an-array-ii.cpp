class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<vector<int>> ans;

        vector<int> arr;

        set<int> st;
        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }

        for(int i=lower; i<=upper; i++) {
            if(st.find(i) == st.end()) {
                arr.push_back(i);
            }
        }

        if(arr.empty()) {
            return {};
        }

        vector<int> res;
        res.push_back(arr[0]);

        for(int i=1; i<arr.size(); i++) {
            if(arr[i] - res.back() == 1) {
                res.push_back(arr[i]);
            }
            else {
                vector<int> v;
                v.push_back(res[0]);
                v.push_back(res[res.size() - 1]);
                
                ans.push_back(v);
                res.clear();

                res.push_back(arr[i]);
            }
        }

        if(!res.empty()) {
            vector<int> v;
            v.push_back(res[0]);
            v.push_back(res[res.size() - 1]);

            ans.push_back(v);
        }

        return ans;
    }
};