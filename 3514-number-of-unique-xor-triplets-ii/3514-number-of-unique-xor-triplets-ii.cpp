class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st2;

        unordered_set<int> st;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                int res = (nums[i] ^ nums[j]);
                st.insert(res);
            }
        }

        for(int i=0; i<n; i++) {
            int k = nums[i];

            for(auto x : st) {
                int value = (x ^ k);
                st2.insert(value);
            }
        }

        return (st2.size());
    }
};