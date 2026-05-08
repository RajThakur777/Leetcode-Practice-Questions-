class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people , 0);

        int idx = 0;
        int n = num_people;
        int val = 1;
        while(idx < n) {
            if(val > candies) {
                break;
            }
            ans[idx] += val;
            candies -= val;
            val++;
            (idx = (idx + 1) % n);
        }

        ans[idx] += candies;

        return ans;
    }
};