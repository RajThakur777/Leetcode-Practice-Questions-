class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , int> mpp;

        int ans = INT_MAX;

        for(int i=0; i<n; i++) {
            int num = nums[i];

            string str = to_string(num);

            reverse(str.begin() , str.end());

            string newStr;
            int idx = -1;
            for(int j=0; j<str.size(); j++) {
                if(str[j] != '0') {
                    idx = j;
                    break;
                }
            }

            if(idx != -1) {
                newStr = str.substr(idx , (str.size() - idx));
            }
            else {
                newStr = str;
            }

            int rev = stoi(newStr);

            if(mpp.find(num) != mpp.end()) {
                ans = min(ans , (i - mpp[num]));
            }
            mpp[rev] = i;
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};