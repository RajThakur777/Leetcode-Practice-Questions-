class Solution {
public:

    int reverse_element(int x) {
        int sum = 0;

        while(x > 0) {
            int dig = x % 10;
            sum += dig;
            x /= 10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int n = nums.size();

        int mini = INT_MAX;
        
        for(int i=0; i<n; i++) {
            int ele = nums[i];

            int num = reverse_element(ele);

            mini = min(mini , num);
        }
        return mini;
    }
};