class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        stack<int> st1;
        vector<int> arr(n);
        arr[n-1] = -1;

        st1.push(nums2[n-1]);

        for(int i=n-2; i>=0; i--) {
            while(!st1.empty() && nums2[i] >= st1.top()) {
                st1.pop();
            }

            if(st1.empty()) {
                arr[i] = -1;
            }
            else {
                arr[i] = st1.top();
            }

            st1.push(nums2[i]);
        }

        map<int , int> mpp;

        for(int i=0; i<n; i++) {
            int ele = nums2[i];
            int ngr = arr[i];

            mpp[ele] = ngr;
        }

        vector<int> ans;

        for(int i=0; i<nums1.size(); i++) {
            ans.push_back(mpp[nums1[i]]);
        }

        return ans;
    }
};