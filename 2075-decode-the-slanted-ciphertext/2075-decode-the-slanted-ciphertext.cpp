class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();

        int columns = (n / rows);

        string ans;

        for(int i=0; i<n; i++) {
            int j = i;

            while(j < n) {
                ans += encodedText[j];
                j += (columns + 1);
            }

            if(ans.size() > n) {
                break;
            }
        }

        string str = ans.substr(0 , n);

        while(!str.empty() && str.back() == ' ') {
            str.pop_back();
        }

        return str;
    }
};