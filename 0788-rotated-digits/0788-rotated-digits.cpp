class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;

        for(int i=1; i<=n; i++) {
            int num = i;

            string str = to_string(num);

            bool f = true;

            for(int j=0; j<str.size(); j++) {
                if(str[j] == '3' || str[j] == '4' || str[j] == '7') {
                    f = false;
                    break;
                }
            }

            string newStr;

            for(int j=0; j<str.size(); j++) {
                if(str[j] == '2') {
                    newStr[j] = '5';
                }
                else if(str[j] == '5') {
                    newStr[j] = '2';
                }
                else if(str[j] == '6') {
                    newStr[j] = '9';
                }
                else if(str[j] == '9') {
                    newStr[j] = '6';
                }
                else {
                    newStr[j] = str[j];
                }
            }

            int num2 = stoi(newStr);

            if((num != num2) && f) {
                ans++;
            }
        }
        return ans;
    }
};