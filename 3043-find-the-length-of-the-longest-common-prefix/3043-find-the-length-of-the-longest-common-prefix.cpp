class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();

        map<string , int> mpp1;

        for(int i=0; i<m; i++) {
            string str = to_string(arr1[i]);

            string res;
            for(int j=0; j<str.size(); j++) {
                res += str[j];
                mpp1[res]++;
            }
        }

        map<string , int> mpp2;
        for(int i=0; i<n; i++) {
            string str = to_string(arr2[i]);

            string res;
            for(int j=0; j<str.size(); j++) {
                res += str[j];
                mpp2[res]++;
            }
        }

        int ans = 0;

        for(auto it : mpp1) {
            if(mpp2.find(it.first) != mpp2.end()) {
                ans = max(ans , (int)(it.first.size()));
            }
        }
        return ans;
    }
};