class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();

        vector<pair<char , int>> arr;

        int cnt = 1;
        char prev = s[0];

        for(int i=1; i<n; i++) {
            if(s[i] == prev) {
                cnt++;
            }
            else {
                arr.push_back({prev , cnt});
                cnt = 1;
                prev = s[i];
            }
        }
        arr.push_back({prev , cnt});

        int i = 0;
        int j = arr.size()-1;

        while(i < j) {
            if(arr[i].first != arr[j].first) {
                break;
            }
            else {
                i++;
                j--;
            }
        }

        if(i == j) {
            if(arr[i].second == 1) {
                return 1;
            }
            
            return 0;
        }

        int ans = 0;

        for(int k=i; k<=j; k++) {
            ans += (arr[k].second);
        }

        return ans;
    }
};