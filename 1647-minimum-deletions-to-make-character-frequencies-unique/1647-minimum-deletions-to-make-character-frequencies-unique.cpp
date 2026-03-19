class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();

        unordered_map<char , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[s[i]]++;
        }

        vector<int> arr;
        for(auto it : mpp) {
            arr.push_back(it.second);
        }

        sort(arr.begin() , arr.end());

        set<int> st;
        st.insert(arr[0]);

        int ops = 0;

        for(int i=1; i<arr.size(); i++) {
            if(st.find(arr[i]) != st.end()) {
                int value = arr[i];
                while(st.find(value) != st.end() && value > 0) {
                    value--;
                }

                if(value == 0) {
                    ops += arr[i];
                }
                else {
                    ops += (arr[i] - value);
                    st.insert(value);
                }
            }
            else {
                st.insert(arr[i]);
            }
        }
        return ops;
    }
};