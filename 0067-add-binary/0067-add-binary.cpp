class Solution {
public:
    string addBinary(string a, string b) {    
        int m = a.size();
        int n = b.size();

        string ans;

        int i = m-1;
        int j = n-1;

        int carry = 0;

        while(i >= 0 && j >= 0) {
            int num1 = (a[i] - '0');
            int num2 = (b[j] - '0');

            int sum = num1 + num2 + carry;

            if(sum == 0) {
                ans += '0';
                carry = 0;
            }
            else if(sum <= 1) {
                ans += '1';
                carry = 0;
            }
            else if(sum == 2) {
                ans += '0';
                carry = 1;
            }
            else {
                ans += '1';
                carry = 1;
            }
            i--;
            j--;
        }  

        if(i < 0) {
            while(j >= 0) {
                int sum = carry + b[j] - '0';

                if(sum == 0) {
                    ans += '0';
                    carry = 0;
                }
                else if(sum == 1) {
                    ans += '1';
                    carry = 0;
                }
                else {
                    ans += '0';
                    carry = 1;
                }
                j--;
            }
            if(carry > 0) {
                ans += '1';
            }
            reverse(ans.begin() , ans.end());

            return ans;
        }
        else if(j < 0) {
            while(i >= 0) {
                int sum = carry + a[i] - '0';

                if(sum == 0) {
                    ans += '0';
                    carry = 0;
                }
                else if(sum == 1) {
                    ans += '1';
                    carry = 0;
                }
                else {
                    ans += '0';
                    carry = 1;
                }
                i--;
            }
            if(carry > 0) {
                ans += '1';
            }
            reverse(ans.begin() , ans.end());

            return ans;
        }
        else {
            if(carry > 0) {
                ans += '1';
            }

            reverse(ans.begin() , ans.end());

            return ans;
        }
    }
};