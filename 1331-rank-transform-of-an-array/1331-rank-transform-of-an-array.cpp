class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {   
        int n = arr.size();

        map<int , int> mpp;

        vector<int> c = arr;
        sort(c.begin() , c.end());

        int prev = 0;

        for(int i=0; i<n; i++) {
            if(mpp.find(c[i]) == mpp.end()) {
                mpp[c[i]] = (prev + 1);
                prev++;

            }
            else {
                continue;
            }
        }

        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            ans[i] = mpp[arr[i]];
        }

        return ans;
    }
};