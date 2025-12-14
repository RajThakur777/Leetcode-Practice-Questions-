class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> a1 = nums;
        vector<int> a2 = nums;

        sort(a1.rbegin() , a1.rend());
        sort(a2.begin() , a2.end());

        int s1 = 0;
        int s2 = 0;

        int cnt1 = k;
        int cnt2 = k;
        for(int i=0; i<n; i++) {
            s1 += a1[i];
            cnt1--;

            if(cnt1 == 0) {
                break;
            }
        }

        for(int i=0; i<n; i++) {
            s2 += a2[i];
            cnt2--;

            if(cnt2 == 0) {
                break;
            }
        }
        return abs(s1 - s2);
    }
};