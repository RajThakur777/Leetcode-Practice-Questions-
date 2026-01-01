class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        vector<int> ans;

        int carry = 0;
        ans.push_back((digits[n-1] + 1) % 10);

        carry = ((digits[n-1] + 1) / 10);

        for(int i=n-2; i>=0; i--) {
            int num = (digits[i] + carry) % 10;
            ans.push_back(num);
            carry = ((digits[i] + carry) / 10);
        }

        if(carry > 0) {
            ans.push_back(carry);
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};