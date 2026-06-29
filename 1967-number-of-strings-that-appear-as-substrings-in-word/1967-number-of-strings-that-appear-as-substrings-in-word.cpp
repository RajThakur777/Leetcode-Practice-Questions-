class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        map<string , int> mpp;

        int n = word.size();

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                string str = word.substr(i , (j - i + 1));

                mpp[str]++;
            }
        }

        int ans = 0;

        for(int i=0; i<patterns.size(); i++) {
            if(mpp.find(patterns[i]) != mpp.end()) {
                ans++;
            }
        }
        return ans;
    }
};