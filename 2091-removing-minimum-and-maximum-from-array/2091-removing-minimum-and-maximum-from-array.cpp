class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int maxi = *max_element(nums.begin() , nums.end());
        int mini = *min_element(nums.begin() , nums.end());

        int i1 = -1;
        int j1 = -1;

        for(int i=0; i<n; i++) {
            if(maxi == nums[i]) {
                i1 = i;
                break;
            }
        }

        for(int i=0; i<n; i++) {
            if(mini == nums[i]) {
                j1 = i;
                break;
            }
        }

        if(i1 == j1) {
            return i1 + 1;
        }

        int r1 = max({i1 , j1}) + 1;
        int r2 = n - min({i1 , j1});

        int r3 = 0;

        if(i1 > j1) {
            r3 += (j1 + 1);
            r3 += (n - i1);
        }
        else {
            r3 += (i1 + 1);
            r3 += (n - j1);
        }

        return min({r1 , r2  ,r3});
    }
};